<template>
  <div>
    <el-row style="height: 950px;">
      <search-bar @onSearch="searchResult" ref="searchBar"></search-bar>
      <view-switch class="switch"></view-switch>
      <el-tooltip effect="dark" placement="right"
                  v-for="item in books.slice((currentPage-1)*pagesize,currentPage*pagesize)"
                  :key="item.id">
        <p slot="content" style="font-size: 14px;margin-bottom: 6px;">{{item.name}}</p>
        <p slot="content" style="font-size: 13px;margin-bottom: 6px">
          <span>{{item.username}}</span> /
          <span>{{item.date}}</span>
        </p>
        <p slot="content" style="width: 100px" class="abstract">{{item.descripte}}</p>
        <el-card style="width: 250px;height: 310px;float: left" class="book" shadow="hover" >
          <el-image style="width: 200px; height: 200px" :src="item.pic" @click.native="openContent(item.id)"></el-image>
          <el-row style="float: center">
            {{item.name}}
          </el-row>
          <el-row style="float: center">
            {{item.borrower}}
          </el-row>
          <el-row style="float: center">
            <el-button type="primary" style="width = 10px" @click="brower(item.id,item.borrower)">借阅</el-button>
            <el-button type="primary" style="width = 10px" @click="comment(item.id,item.name)">评价</el-button>
          </el-row>
        </el-card>
      </el-tooltip>
    </el-row>
    <el-row>
      <el-pagination
        @current-change="handleCurrentChange"
        :current-page="currentPage"
        :page-size="pagesize"
        :total="books.length">
      </el-pagination>
    </el-row>
    <el-dialog
      title="评论内容"
      :visible.sync="dialogVisible"
      width="30%">
      <span>
          <el-input type="textarea" v-model="input" :autosize="{ minRows: 3, maxRows: 100}"></el-input>
      </span>
      <span slot="footer" class="dialog-footer">
        <el-button @click="dialogVisible = false">取 消</el-button>
        <el-button type="primary" @click="commit()">提交</el-button>
      </span>
    </el-dialog>

    <el-dialog
      title="所有评论"
      :visible.sync="commentDialogVisible"
      width="30%"
      height = "1000px">
          <el-row style="float: center" v-for="item in comments"
                  :key="item.id">
            {{item.user+': '+ item.context}}
            <el-divider></el-divider>
          </el-row>

    </el-dialog>
  </div>
</template>

<script>
import SearchBar from './SearchBar'
import ViewSwitch from './ViewSwitch'

export default {
  name: 'Books',
  components: {SearchBar, ViewSwitch},
  data () {
    return {
      input: '',
      books: [],
      currentPage: 1,
      pagesize: 18,
      bookid: 0,
      bookname: 'lala',
      dialogVisible: false,
      commentDialogVisible: false,
      comments: []
    }
  },
  mounted: function () {
    this.loadBooks()
  },
  methods: {
    loadBooks () {
      var _this = this
      this.$axios.post('/books').then(resp => {
        if (resp.data.code === 200) {
          _this.books = resp.data.result
          console.log(resp.data.result)
        }
      })
    },
    handleCurrentChange: function (currentPage) {
      this.currentPage = currentPage
    },
    searchResult () {
      var _this = this
      this.$axios
        .get('/search?keywords=' + this.$refs.searchBar.keywords, {
        }).then(resp => {
          if (resp && resp.data.code === 200) {
            _this.books = resp.data.result
          }
        })
    },
    brower (id, username) {
      var _this = this
      if (typeof window.localStorage.getItem('username' || '[]') !== 'undefined') {
        this.$axios
          .post('/apply', {
            bookid: id,
            mastername: username,
            borrowername: JSON.parse(window.localStorage.getItem('username' || '[]')).username}).then(resp => {
            if (resp && resp.data.code === 200) {
              _this.$alert('借阅申请已经发送，等待确定', '提示', {
                confirmButtonText: '确定'
              })
            } else {
              this.$alert('现在书就在你的手上，借个锤子', '提示', {
                confirmButtonText: '确定'
              })
            }
          })
      }
    },
    comment (id, name) {
      this.dialogVisible = true
      this.bookid = id
      this.bookname = name
    },
    commit () {
      var _this = this
      if (typeof window.localStorage.getItem('username' || '[]') !== 'undefined') {
        this.$axios
          .post('/comment', {
            bookid: this.bookid,
            bookname: this.bookname,
            context: this.input,
            user: JSON.parse(window.localStorage.getItem('username' || '[]')).username}).then(resp => {
            if (resp && resp.data.code === 200) {
              _this.$alert('评论已提交！', '提示', {
                confirmButtonText: '确定'
              })
              this.input = ''
              this.dialogVisible = false
            }
          })
      }
    },
    openContent (id) {
      this.$axios
        .get('/allcomment?bookid=' + id, {}).then(resp => {
          if (resp && resp.data.code === 200) {
            this.comments = resp.data.result
          }
        })
      this.commentDialogVisible = true
    }

  }
}
</script>
<style scoped>
  .cover {
    width: 115px;
    height: 172px;
    margin-bottom: 7px;
    overflow: hidden;
    cursor: pointer;
  }

  img {
    width: 200px;
    height: 200px;
    /*margin: 0 auto;*/
  }

  .title {
    font-size: 14px;
    text-align: left;
  }

  .author {
    color: #333;
    width: 102px;
    font-size: 13px;
    margin-bottom: 6px;
    text-align: left;
  }

  .abstract {
    display: block;
    line-height: 17px;
  }

  .el-icon-delete {
    cursor: pointer;
    float: right;
  }

  .switch {
    display: flex;
    position: absolute;
    left: 780px;
    top: 25px;
  }

  a {
    text-decoration: none;
  }

  a:link, a:visited, a:focus {
    color: #3377aa;
  }

</style>

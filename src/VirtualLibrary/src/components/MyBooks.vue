<template>
  <div>
    <el-row style="height: 840px;margin-left:100px;margin-top:100px;">
        <el-card style="width: 250px;height: 310px;float: left" shadow="hover" v-for="item in myBooks.slice((currentPage-1)*pagesize,currentPage*pagesize)"
                  :key="item.id">
          <el-image style="width: 200px; height: 200px" :src="item.pic" :lazy='true'></el-image>
          <el-row style="float: center">
            {{'拥有人： ' + item.username}}
          </el-row>
          <el-row style="float: center">
            {{'现存于： ' + item.borrower}}
          </el-row>
          <el-row style="float: center">
            <el-button type="submit" style="width = 10px" @click="offShelf(item.id)" v-if="item.username === item.borrower">下架</el-button>
            <el-button type="submit" style="width = 10px" @click="back(item.id)" v-if="item.username !== item.borrower">归还</el-button>
          </el-row>
        </el-card>
    </el-row>
    <el-row>
      <el-pagination
        @current-change="handleCurrentChange"
        :current-page="currentPage"
        :page-size="pagesize"
        :total="myBooks.length">
      </el-pagination>
    </el-row>
  </div>
</template>

<script>

export default {
  name: 'MyBooks',
  data () {
    return {
      myBooks: [],
      currentPage: 1,
      pagesize: 18,
      show: true
    }
  },
  mounted: function () {
    this.loadMyBooks()
  },
  methods: {
    loadMyBooks () {
      var _this = this
      if (typeof window.localStorage.getItem('username' || '[]') !== 'undefined') {
        this.$axios.get('/books?username=' + JSON.parse(window.localStorage.getItem('username' || '[]')).username, {
        }).then(resp => {
          if (resp.data.code === 200) {
            _this.myBooks = resp.data.result
          }
        })
      }
    },
    handleCurrentChange: function (currentPage) {
      this.currentPage = currentPage
    },
    offShelf (bookid) {
      this.$axios.get('/offshelf?bookid=' + bookid, {
      }).then(resp => {
        if (resp.data.code === 200) {
          this.$alert(resp.data.message + '下架成功！', '提示', {
            confirmButtonText: '确定'
          })
          this.loadMyBooks()
        }
      })
    },
    back (bookid) {
      this.$axios.post('/back', {
        bookid: bookid
      }).then(resp => {
        if (resp.data.code === 200) {
          this.$alert(resp.data.message + '归还成功！', '提示', {
            confirmButtonText: '确定'
          })
          this.loadMyBooks()
        }
      })
    }
  }
}
</script>

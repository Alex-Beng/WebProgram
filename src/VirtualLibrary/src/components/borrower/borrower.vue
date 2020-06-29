<template>
  <div>
    <el-row style="height: 840px;margin-left:100px;margin-top:100px;">
        <el-card style="width: 250px;height: 310px;float: left" shadow="hover" v-for="item in borrowers.slice((currentPage-1)*pagesize,currentPage*pagesize)"
                  :key="item.id">
          <el-image style="width: 200px; height: 200px" :src="item.book.pic" :lazy='true'></el-image>
          <el-row style="float: center">
            {{'借阅人: '+item.borrower.borrowername}}
          </el-row>
          <el-row style="float: center">
            {{item.username}}
          </el-row>
          <el-row style="float: center">
            <el-button type="submit" style="width = 10px" @click="process( 'agree', item.book.id,item.borrower.id)">同意</el-button>
            <el-button type="submit" style="width = 10px" @click="process( 'disagree', item.book.id,item.borrower.id)">拒绝</el-button>
          </el-row>
        </el-card>
    </el-row>
    <el-row>
      <el-pagination
        @current-change="handleCurrentChange"
        :current-page="currentPage"
        :page-size="pagesize"
        :total="borrowers.length">
      </el-pagination>
    </el-row>
  </div>
</template>

<script>

export default {
  name: 'Borrower',
  data () {
    return {
      borrowers: [],
      currentPage: 1,
      pagesize: 18
    }
  },
  mounted: function () {
    this.loadBorrower()
  },
  methods: {
    loadBorrower () {
      var _this = this
      if (typeof window.localStorage.getItem('username' || '[]') !== 'undefined') {
        this.$axios.get('/applyList?name=' + JSON.parse(window.localStorage.getItem('username' || '[]')).username, {
        }).then(resp => {
          if (resp.data.code === 200) {
            _this.borrowers = resp.data.result
          }
        })
      }
    },
    handleCurrentChange: function (currentPage) {
      this.currentPage = currentPage
    },
    process (opinion, bookid, borrowerid) {
      var _this = this
      this.$axios.post('/processApply', {
        opinion: opinion,
        bookid: bookid,
        borrowerid: borrowerid
      }).then(resp => {
        if (resp.data.code === 200) {
          console.log(resp.data.message)
          this.$alert(resp.data.message + '了一个借阅申请', '提示', {
            confirmButtonText: '确定'
          })
          _this.loadBorrower()
        }
      })
    }
  }
}
</script>
<style scoped>

</style>

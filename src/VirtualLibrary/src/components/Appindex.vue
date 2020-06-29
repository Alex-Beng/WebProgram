<template>
<body id="index">
  <el-form ref="form" :model="form" label-width="80px" class="index-container">
    <el-form-item label="图书名称" prop="name">
      <el-input v-model="form.name"></el-input>
    </el-form-item>
    <el-form-item label="图书图片" prop="pic">
      <el-input v-model="form.pic"></el-input>
    </el-form-item>
    <!-- <el-form-item label="上传图片" style="width=80px" prop="pic">
        <el-upload
          v-model="form.pic"
          class="upload-pic"
          drag
          limit=1
          action="https://jsonplaceholder.typicode.com/posts/"
          auto-upload="false"
          :on-preview="handlePreview"
          :on-remove="handleRemove"
          :file-list="fileList"
          list-type="picture">
          <div class="el-upload__text">将文件拖到此处，或<em>点击上传</em></div>
          <div slot="tip" class="el-upload__tip">只能上传jpg/png文件，且不超过500kb</div>
        </el-upload>
    </el-form-item> -->
    <el-form-item label="出版时间" prop="date">
      <el-col :span="11">
        <el-date-picker type="date" placeholder="选择日期" v-model="form.date" style="width: 100%;"></el-date-picker>
      </el-col>
    </el-form-item>
    <el-form-item label="图书种类" prop="radio">
      <el-radio-group v-model="form.radio" name="kind">
        <el-radio label="1">文学</el-radio>
        <el-radio label="2">中国</el-radio>
        <el-radio label="3">外国</el-radio>
        <el-radio label="4">计算机</el-radio>
      </el-radio-group>
    </el-form-item>
    <el-form-item label="图书描述" prop="desc">
      <el-input type="textarea" v-model="form.desc" :autosize="{ minRows: 3, maxRows: 100}"></el-input>
    </el-form-item>
    <el-form-item>
      <el-button type="primary" @click="onSubmit">立即上架</el-button>
    </el-form-item>
  </el-form>
</body>
</template>

<script>
export default {
  name: 'AppIndex',
  data () {
    return {
      form: {
        name: '',
        date: '',
        desc: '',
        pic: '',
        radio: 3
      }
    }
  },
  methods: {
    handleRemove (file, fileList) {
      console.log(file, fileList)
    },
    handlePreview (file) {
      console.log(file)
    },
    onSubmit () {
      console.log('submit!')
      var _this = this
      if (typeof window.localStorage.getItem('username' || '[]') !== 'undefined') {
        this.$axios
          .post('/upload', {
            username: JSON.parse(window.localStorage.getItem('username' || '[]')).username,
            name: this.form.name,
            date: this.form.date,
            descripte: this.form.desc,
            pic: this.form.pic,
            kind: this.form.radio
          })
          .then(resp => {
            if (resp.data.code === 200) {
              _this.$refs.form.resetFields()
              _this.$alert(resp.data.message, '提示', {
                confirmButtonText: '确定'
              })
            } else {
              this.$alert(resp.data.message, '提示', {
                confirmButtonText: '确定'
              })
            }
          })
          .catch(failResponse => {})
      }
    }
  }
}
</script>
<style>
  #index {
    background:url("../assets/login.jpg") no-repeat;
    background-position: center;
    height: 100%;
    width: 100%;
    background-size: cover;
  }
  body{
    margin: 0;
  }
  .index-container {
    border-radius: 15px;
    background-clip: padding-box;
    padding: 35px 35px 15px 35px;
    height: 900px;
    width: 600px;
    margin: 0px auto;
    background: #ffffff;

    /* border: 1px solid #eaeaea; */
    /* box-shadow: 0 0 25px #cac6c6; */
  }
</style>

  <!-- <template>
<div>
  <el-menu
      default-active="2"
      mode="horizontal"
      class="el-menu-vertical-demo"
      @open="handleOpen"
      @close="handleClose"
      background-color="#545c64"
      text-color="#fff"
      active-text-color="#ffd04b"
      style = "height: 100%">
<el-menu-item index="1">上架图书</el-menu-item>
  <el-submenu index="2">
    <template slot="title">我的图书</template>
    <el-menu-item index="2-1">已借阅</el-menu-item>
    <el-menu-item index="2-2">暂未借阅</el-menu-item>
  </el-submenu>
  <el-menu-item index="3">图书馆</el-menu-item>
  <el-menu-item index="4">我的借阅</el-menu-item>
  </el-menu>
</div>
   <div class="left_menu" style="height: 100%">
   <el-row class="tac" style="height: 100%">
   <el-col :span="4">
    <el-menu
      default-active="2"
      mode="horizontal"
      class="el-menu-vertical-demo"
      @open="handleOpen"
      @close="handleClose"
      background-color="#545c64"
      text-color="#fff"
      active-text-color="#ffd04b"
      style = "height: 100%">
      <el-submenu index="1">
        <template slot="title">
          <i class="el-icon-s-platform"></i>
          <span>服务大厅</span>
        </template>
        <el-menu-item-group>
          <el-menu-item index="1-1">在场服务</el-menu-item>
          <el-menu-item index="1-2">历史服务</el-menu-item>
        </el-menu-item-group>
      </el-submenu>
      <el-submenu index="2">
        <template slot="title">
          <i class="el-icon-s-tools"></i>
          <span>系统设置</span>
        </template>
        <el-menu-item-group>
          <el-menu-item index="1-1">权限管理</el-menu-item>
          <el-menu-item index="1-2">角色管理</el-menu-item>
        </el-menu-item-group>
      </el-submenu>
      <el-submenu index="3">
        <template slot="title">
          <i class="el-icon-user-solid"></i>
          <span>人员数据</span>
        </template>
        <el-menu-item-group>
          <el-menu-item index="1-1">人员数量</el-menu-item>
          <el-menu-item index="1-2">人员位置</el-menu-item>
        </el-menu-item-group>
      </el-submenu>
      <el-submenu index="4">
        <template slot="title">
          <i class="el-icon-message-solid"></i>
          <span>健康报警</span>
        </template>
        <el-menu-item-group>
          <el-menu-item index="1-1">心率报警</el-menu-item>
          <el-menu-item index="1-2">血压报警</el-menu-item>
        </el-menu-item-group>
      </el-submenu>
    </el-menu>
  </el-col>
</el-row>
  </div>
</template> -->

<!-- <script>
export default {
  methods: {
    handleOpen (key, keyPath) {
      console.log(key, keyPath)
    },
    handleClose (key, keyPath) {
      console.log(key, keyPath)
    }
  }
}
</script> -->

<!--<template>
  <div>
  <el-col :span="2">
    <el-menu
      :default-active="this.$route.path"
      router mode="horizontal"
      class="el-menu-vertical-demo"
      @open="handleOpen"
      @close="handleClose"
      background-color="#545c64"
      text-color="#fff"
      active-text-color="#ffd04b">
      <el-menu-item v-for="(item,i) in navList" :key="i" :index="item.name">
        <template slot="title">
          <i class="el-icon-s-platform"></i>
          <span> {{ item.navItem }}</span>
        </template>

      </el-menu-item>
    </el-menu>
  </el-col>
  <router-view     class="menu-right"/>
  </div>
</template>

<script>
export default {
  data () {
    return {
      navList: [
        {name: '/components/ServiceHall', navItem: '服务大厅'},
        {name: '/components/Management', navItem: '权限管理'},
        {name: '/components/User', navItem: '用户管理'},
        {name: '/components/Personnel', navItem: '人员数据'}
      ]
    }
  },
  methods: {
    handleOpen (key, keyPath) {
      console.log(key, keyPath)
    },
    handleClose (key, keyPath) {
      console.log(key, keyPath)
    }
  }
}
</script>-->
<template>
  <div>
    <el-menu
      :default-active="currentPath"
      router
      mode="horizontal"
      background-color="#545c64"
      text-color="#fff"
      active-text-color="red"
      style="min-width: 1300px">
      <el-menu-item v-for="(item,i) in navList" :key="i" :index="item.name">
        {{ item.navItem }}
      </el-menu-item>
      <!-- <span style="position: absolute;padding-top: 20px; right: 43%;font-size: 20px;font-weight: bold;color:#fff">{{JSON.parse(window.localStorage.getItem('username' || '[]')).username}}</span> -->
      <el-row style="position: absolute;padding-top: 20px; right: 43%;font-size: 20px;font-weight: bold;color:#A0EEE1">
        {{username}}
      </el-row>
      <el-row style="position: absolute;padding-top: 20px; right: 43%;font-size: 20px;font-weight: bold;color:#ffff">
        {{'的图书馆'}}
      </el-row>
      <!-- <el-input
        placeholder="快速搜索..."
        prefix-icon="el-icon-search"
        size="medium"
        style="width: 100px;position:absolute;margin-top: 12px;right: 20%"
        v-model="keywords">
      </el-input> -->
      <el-button type="primary" icon="el-icon-s-promotion" @click="logout()" style="position: absolute;margin-top: 12px; right: 5%;" round>登出</el-button>
    </el-menu>
  </div>
</template>

<script>
export default {
  name: 'NavMenu',
  data () {
    return {
      navList: [
        {name: '/index', navItem: '上架图书'},
        {name: '/mybooks', navItem: '我的图书'},
        {name: '/library', navItem: '图书馆'},
        {name: '/borrower', navItem: '借阅申请'}
      ],
      keywords: '',
      username: JSON.parse(window.localStorage.getItem('username' || '[]')).username + '的图书馆'
    }
  },
  computed: {
    hoverBackground () {
      return '#ffd04b'
    },
    currentPath () {
      var x = this.$route.path.indexOf('/', 1)
      if (x !== -1) {
        return this.$route.path.substring(0, x)
      } else {
        return this.$route.path
      }
    }
  },
  methods: {
    logout () {
      var self = this
      this.$confirm('你确定退出吗?', '退出图书管理平台', {
        confirmButtonText: '确定',
        cancelButtonText: '取消'
      }).then(() => {
        window.localStorage.clear()
        self.$router.replace('/login')
      }).catch(() => {

      })
    }
  }
}
</script>

<style scoped>
  a{
    text-decoration: none;
  }

  span {
    pointer-events: none;
  }

</style>

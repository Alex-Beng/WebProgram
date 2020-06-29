
import Vue from 'vue'
// import Vuex from 'vuex'
import Router from 'vue-router'
// 导入刚才编写的组件
import AppIndex from '@/components/AppIndex'
import Login from '@/components/Login'
import Home from '../components/Home'

Vue.use(Router)
// Vue.use(Vuex)

// export default new Vuex.Store(

// )

export default new Router({
  mode: 'history',
  routes: [
  // 下面都是固定的写法
    {
      path: '/home',
      name: 'Home',
      component: Home,
      // home页面并不需要被访问
      redirect: '/index',
      children: [
        {
          path: '/index',
          name: 'AppIndex',
          component: AppIndex,
          meta: {
            requireAuth: true
          }
        },
        {
          path: '/library',
          name: 'Library',
          component: () => import('../components/library/LibraryIndex')
        },
        {
          path: '/borrower',
          name: 'Borrower',
          component: () => import('../components/borrower/borrower')
        },
        {
          path: '/mybooks',
          name: 'MyBooks',
          component: () => import('../components/MyBooks')
        }
      ]
    },
    {
      path: '/login',
      name: 'Login',
      component: Login
    },
    {
      path: '/register',
      name: 'Register',
      component: () => import('../components/Register')
    }
  ]
})

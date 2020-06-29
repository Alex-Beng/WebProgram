import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    user: {
      username: (window.localStorage.getItem('username' || '[]') == null || (typeof window.localStorage.getItem('user' || '[]') === 'undefined')) ? '' : JSON.parse(window.localStorage.getItem('username' || '[]'))
    }
  },
  mutations: {
    login (state, user) {
      state.user = user
      window.localStorage.setItem('username', JSON.stringify(user))
    }
  }
})

import React from "react";
import SignUp from "./components/SignUp";
import Login from "./components/Login";
import { BrowserRouter, Link, Route, Switch } from "react-router-dom";
import Dashboard from "./components/Dashboard";
import UpdateProfile from "./components/UpdateProfile";
import PrivateRoute from './PrivateRoute';
function App() {
  return (
    <BrowserRouter>
      <PrivateRoute path="/" exact component={Dashboard} />
      <Route path="/" exact component={Dashboard} />
      <Route path="/login" exact component={Login} />
      <Route path="/signup" exact component={SignUp} />
      <PrivateRoute path="/profile" exact component={UpdateProfile} />
    </BrowserRouter>
  );
}

export default App;

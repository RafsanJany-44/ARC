import React,{useState} from 'react';

const AuthContext = React.createContext();

const AuthProvider=(props)=>{
    let [isLogged,setisLogged]=useState(false);
    let [currentUser,setcurrentUser]=useState({});

    return(
        <AuthContext.Provider
        value={{
            currentUser:currentUser,
            setcurrentUser:setcurrentUser,
            isLogged:isLogged,
            setisLogged:setisLogged,
        }}>
            {props.children}
        </AuthContext.Provider>
    );
};


export {AuthProvider,AuthContext};

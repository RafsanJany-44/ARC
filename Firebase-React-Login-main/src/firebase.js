import firebase from "firebase/app";
import "firebase/auth";

const app = firebase.initializeApp({
    apiKey: "AIzaSyDZfPO7GpgyfLTDaXjdtkyVFLYCuiSOhOQ",
    authDomain: "fir-auth-development-df85c.firebaseapp.com",
    projectId: "fir-auth-development-df85c",
    storageBucket: "fir-auth-development-df85c.appspot.com",
    messagingSenderId: "301673670781",
    appId: "1:301673670781:web:fbb89b11a3b8c9bb536914",
    measurementId: "G-NRQ9G00S5M"
});

const auth = app.auth();
export { auth };
export default app;
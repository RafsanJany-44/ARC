import React, { useState } from "react";
import { Card, Alert, Button, Container } from "react-bootstrap";
import { useAuth } from "./../contexts/AuthContext";
import { Link, useHistory } from "react-router-dom";
const Dashboard = () => {
    const [error, setError] = useState('');
    const { currentUser, logout } = useAuth();
    const history = useHistory();
    const handleLogout = async () => {
        setError('')
        try {
            await logout().then(() => {
                history.push("/login")
            })
        } catch (error) {
            setError(error)
        }
    }
    return (
        <Container className='d-flex-align-items-center justify-content-center'
            style={{ minHeight: "100vh", marginTop: "5%", width: "40%" }}>
            <div>
                <Card>
                    <Card.Body>
                        <h2 className='text-center mb-4'>Profile</h2>
                        {error ? <Alert variant='danger'>{JSON.stringify(error)}</Alert> : ""}
                        <strong>Email: </strong>
                        {currentUser && currentUser.email}
                        <Link to="/profile" className='btn btn-primary w-100 mt-3'> Update </Link>
                    </Card.Body>
                </Card>
                <div className='w-100 text-center mt-2'>
                    <Button variant="Link" onClick={handleLogout}>Log Out</Button>
                </div>
            </div>
        </Container>
    )
}

export default Dashboard;
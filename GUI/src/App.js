import React from 'react';
import logo from './logo.svg';
import './App.css';
import Button from '@material-ui/core/Button'
import LocalBarIcon from '@material-ui/icons/LocalBar'

import 'fontsource-roboto';

import Typography from '@material-ui/core/Typography'

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <Typography variant="h1">
          Robot Bartender
        </Typography>
        <Typography variant="h5">
          By Drinkers With an Engineering Problem
        </Typography>
        <img src={logo} className="App-logo" alt="logo" />
        <Button 
          endIcon={<LocalBarIcon />}
          size="large"
          style={{
            fontSize: 24
          }}
          variant="contained">
          Start Here
        </Button>
      </header>
    </div>
  );
}

export default App;

const express = require('express');
const mysql = require('mysql2');
const app = express();
app.use(cors());           // Enable CORS for all routes
app.use(express.json());   // Parse JSON bodies

// Your DB and routes below...


const db = mysql.createConnection({
  host: 'localhost',
  user: 'myuser',
  password: 'MyS3cureP@ssw0rd!',
  database: 'crate'

});

db.connect(err => {
  if (err) {
    console.error('DB connection error:', err);
    process.exit(1);
  }
  console.log('Connected to MySQL!');
});

app.use(express.json()); // to parse JSON body

// GET users
app.get('/users', (req, res) => {
  db.query('SELECT * FROM users', (err, results) => {
    if (err) return res.status(500).json({ error: 'Database query error' });
    res.json(results);
  });
});

// POST add a user
app.post('/users', (req, res) => {
  const { name, password, gmail } = req.body;

  if (!name || !password || !gmail) {
    return res.status(400).json({ error: 'Please provide name, password, and gmail' });
  }

  const sql = 'INSERT INTO users (name, password, gmail) VALUES (?, ?, ?)';
  db.query(sql, [name, password, gmail], (err, result) => {
    if (err) {
      console.error(err);
      return res.status(500).json({ error: 'Failed to add user' });
    }
    res.json({ message: 'User added', userId: result.insertId });
  });
});

const PORT = 3000;
app.listen(PORT, '0.0.0.0', () => {
  console.log(`API server running at http://0.0.0.0:${PORT}`);
});

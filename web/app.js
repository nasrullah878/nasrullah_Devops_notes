const mysql = require('mysql2');

const db = mysql.createConnection({
  host: 'localhost',
  user: 'myuser',          // your MySQL username
  password: 'MyS3cureP@ssw0rd!',  // your MySQL password
  database: 'crate'
});

db.connect((err) => {
  if (err) {
    console.error('DB connection error:', err);
    return;
  }
  console.log('Connected to MySQL!');
  
  db.query('SELECT * FROM users', (err, results) => {
    if (err) throw err;
    console.log('Users:', results);
    db.end();
  });
});

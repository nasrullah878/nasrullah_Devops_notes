<?php
session_start();
$error = '';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Update connection with your database details
    $conn = new mysqli("localhost", "nasrullah", "QueerKhan@125", "nk");

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    $user = $_POST['username'];
    $pass = $_POST['password'];

    // Prepare statement to prevent SQL injection
    $stmt = $conn->prepare("SELECT password FROM users WHERE username=?");
    $stmt->bind_param("s", $user);
    $stmt->execute();
    $stmt->store_result();

    if ($stmt->num_rows > 0) {
        $stmt->bind_result($hashed_password);
        $stmt->fetch();

        if (password_verify($pass, $hashed_password)) {
            $_SESSION['username'] = $user;
            header("Location: dashboard.php");
            exit();
        } else {
            $error = "Invalid password.";
        }
    } else {
        $error = "User not found.";
    }

    $stmt->close();
    $conn->close();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>Login</title>
<style>
body{font-family:sans-serif; display:flex; justify-content:center; align-items:center; height:100vh; background:#0f172a; color:#fff;}
form{background:#111827; padding:24px; border-radius:12px;}
input{display:block; margin:10px 0; padding:8px; border-radius:6px; border:none; width:100%;}
button{padding:10px; border:none; border-radius:6px; background:#38bdf8; color:#001018; cursor:pointer;}
.error{color:#f87171;}
</style>
</head>
<body>
<form method="POST">
    <h2>Login</h2>
    <?php if($error) echo "<div class='error'>$error</div>"; ?>
    <input type="text" name="username" placeholder="Username" required>
    <input type="password" name="password" placeholder="Password" required>
    <button type="submit">Login</button>
</form>
</body>
</html>

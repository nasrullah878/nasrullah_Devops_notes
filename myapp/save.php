<?php
include 'config.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $names = $_POST['name'];
    $emails = $_POST['email'];
    $addresses = $_POST['address'];

    for ($i = 0; $i < count($names); $i++) {
        $name = $conn->real_escape_string($names[$i]);
        $email = $conn->real_escape_string($emails[$i]);
        $address = $conn->real_escape_string($addresses[$i]);

        $sql = "INSERT INTO students (name, email, address) VALUES ('$name', '$email', '$address')";
        $conn->query($sql);
    }

    echo "✅ Students saved successfully!<br>";
    echo "<a href='index.php'>Go back</a>";
}
?>

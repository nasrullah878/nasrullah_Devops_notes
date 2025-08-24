<!DOCTYPE html>
<html>
<head>
    <title>Student Dashboard</title>
</head>
<body>
    <h2>Enter Student Information</h2>
    <form method="post" action="save.php">
        <?php for($i=1; $i<=2; $i++): ?>
            <h3>Student <?php echo $i; ?></h3>
            Name: <input type="text" name="name[]" required><br>
            Email: <input type="email" name="email[]" required><br>
            Address: <input type="text" name="address[]" required><br><br>
        <?php endfor; ?>
        <input type="submit" value="Save Students">
    </form>
</body>
</html>

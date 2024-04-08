<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta name="author" content="River Bumpas and Surya Malik">
        <title>Final Grade/ GPA Calculator</title>
        <meta name="description" content="This page is for calculating a students final grade in a course and overall GPA.">
        <link href="style.css" rel="stylesheet" type="text/css" media="screen" />
    </head>
    <body>
    	<header>
    		<h1>Final Grade and GPA Calculator</h1>
            
    	</header>

        <nav class="menu">
            <ul>
                <li><a href="grade.php">Final Grade Calculator</a></li>
                <li><a href="gpa.php">GPA Calculator</a></li>
            </ul>
        </nav>

        <main>
            <h2> GPA Calculator </h2>
            <p> 
                <form id="gpaCalculator" action='gpaToFile.php' method="POST">
                    <div id="totalGrades">
                        <!-- Default grade -->
                        <div id="grade1">
                            <fieldset>
                                <legend>Grade 1</legend>
                                <input type="text" name="course1[0]" placeholder="Course Name" required>
                                <input type="number" name="course1[1]" placeholder="# of Credits" required min="1" max="19" step="1">
                                <input type="text" name="course1[2]" placeholder="Grade" required>
                            </fieldset>
                        </div>
                        <!-- Grades added dynamically using javascript -->
                    </div>
                    <button type="button" id="addGrade">Add Grade</button>
                    <input type="submit" value="Calculate GPA">
                </form>

                <script src="gpa.js"></script>
            </p>

    </body>
</html>
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
            <h2> Final Grade Calculator </h2><br>
            <p>
                <form id="finalGrade" action="finalGradeToFile.php" method="post">
                    <div id="totalCourses">
                        <!-- Pre-defined Course -->
                        <div id="course1">
                            <fieldset>
                                <legend>Course 1</legend>
                                <input type="text" name="courses[1][name]" placeholder="Course Name" required>
                                <div class="totalCategories">
                                    <!-- Pre-defined Category -->
                                    <div id="category1">
                                        <fieldset>
                                            <legend>Category 1</legend>
                                            <input type="text" name="courses[1][categories][1][name]" placeholder="Category Name" required>
                                            <input type="number" name="courses[1][categories][1][weight]" placeholder="Weight (decimal)" required min="0" max="1" step="0.01">
                                            <div class="totalAssignments">
                                                <!-- Pre-defined Assignment -->
                                                <div id="assignment1">
                                                    <fieldset>
                                                        <legend>Assignment 1</legend>
                                                        <input type="text" name="courses[1][categories][1][assignments][1][name]" placeholder="Assignment Name" required>
                                                        <input type="number" name="courses[1][categories][1][assignments][1][score]" placeholder="Score" required min="0" step="0.01">
                                        
                                                    </fieldset>
                                                </div>
                                            </div>
                                            <button type="button" class="addAssignment">Add Assignment</button>
                                        </fieldset>
                                    </div>
                                </div>
                                <button type="button" class="addCategory">Add Category</button>
                            </fieldset>
                        </div>
                        <!-- Courses, categories, and assignments added dynamically using javascript -->
                    </div>
                    <button type="button" id="addCourse">Add Course</button>
                    <input type="submit" value="Calculate Grade"></button>
                </form>

                <script src="finalGrade.js"></script>
            </p>
        </main>
    </body>
</html>
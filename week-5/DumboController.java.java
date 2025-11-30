import uk.ac.warwick.dcs.maze.logic.IRobot;
import java.util.ArrayList;

public class ExN
{

  public void controlRobot(IRobot robot) {
    /*
    int direction;
    int randno;

    direction = robot.look(IRobot.AHEAD);
    if (robot.look(IRobot.AHEAD) == IRobot.WALL) {
	lookHeading(robot, IRobot.NORTH);

    }
    */

    /*
    do {

       randno = (int) Math.round(Math.random()*3);



       if (randno == 0)
	    direction = IRobot.LEFT;
       else if (randno == 1)
            direction = IRobot.RIGHT;
       else if (randno == 2)
            direction = IRobot.BEHIND;
       else
            direction = IRobot.AHEAD;

    } while (robot.look(direction)==IRobot.WALL);
    */


    //robot.face(direction); /* Face the direction */

    int heading = headingController(robot);
    // System.out.println("HI");

    //call to test harness
     ControlTest.test(heading, robot);

   //set the robot to move in the direction of the heading selected
     robot.setHeading(heading);
     System.out.println(IRobot.EAST);
     // robot.face(IRobot.AHEAD);


  }


    //method detecting whether target is north of robot
    private byte isTargetNorth(IRobot robot) {
	byte resultNorth = 0;

	if (robot.getLocation().y > robot.getTargetLocation().y) {
	    resultNorth = 1;

        } else if (robot.getLocation().y < robot.getTargetLocation().y) {
	     resultNorth = -1;

	} else {
	     resultNorth = 0;
	}

	return resultNorth;


    }

    //method detecting whether target is east of robot
    private byte isTargetEast(IRobot robot) {
	byte resultEast = 0;

	if (robot.getLocation().x > robot.getTargetLocation().x) {
	    resultEast = -1;

        } else if (robot.getLocation().x < robot.getTargetLocation().x) {
	     resultEast = 1;

	} else {
	     resultEast = 0;
	}

	return resultEast;


    }

    //test harness
    public void reset() {
	   ControlTest.printResults();
    }


    // determines the state of the square in a specific absolute direction
    private int lookHeading(IRobot robot, int heading) {
   	int state;
        state = IRobot.PASSAGE;

	String absoluteDirection = "";
	int orgHeading = 0;

	 // north
          if (heading == IRobot.NORTH) {
	    //stores original heading of the robot BEFORE it is modified
	    orgHeading = robot.getHeading();
	    robot.setHeading(IRobot.NORTH);

	    //use robot.look(AHEAD) to return the state of the square in absolute direction set
	    if (robot.look(IRobot.AHEAD) == IRobot.WALL) {
		state = IRobot.WALL;
		absoluteDirection = "NORTH";

	    }	else if (robot.look(IRobot.AHEAD) == IRobot.PASSAGE) {
		    state = IRobot.PASSAGE;
		    absoluteDirection = "NORTH";
	    }	else  {
		    state = IRobot.BEENBEFORE;
		    absoluteDirection = "NORTH";
	    }
	    robot.setHeading(orgHeading);


	 //south
	 } else if (heading == IRobot.SOUTH) {
	    orgHeading = robot.getHeading();
	    robot.setHeading(IRobot.SOUTH);

	    if (robot.look(IRobot.AHEAD) == IRobot.WALL) {
		state = IRobot.WALL;
	        absoluteDirection = "SOUTH";


	    }	else if (robot.look(IRobot.AHEAD) == IRobot.PASSAGE) {
		    state = IRobot.PASSAGE;
		    absoluteDirection = "SOUTH";

	    }	else  {
		    state = IRobot.BEENBEFORE;
		    absoluteDirection = "SOUTH";
	    }
	    robot.setHeading(orgHeading);

        //east
	  }  else if (heading  == IRobot.EAST) {
	       orgHeading = robot.getHeading();
	       robot.setHeading(IRobot.EAST);


	       if (robot.look(IRobot.AHEAD) == IRobot.WALL) {
	         state = IRobot.WALL;
		 absoluteDirection = "EAST";

	       }  else if (robot.look(IRobot.AHEAD) == IRobot.PASSAGE) {
		    state = IRobot.PASSAGE;
		    absoluteDirection = "EAST";

	       }  else  {
		    state = IRobot.BEENBEFORE;
		    absoluteDirection = "EAST";
	       }

	       robot.setHeading(orgHeading);

	 // west
	  } else if (heading == IRobot.WEST) {
	      orgHeading = robot.getHeading();
	      robot.setHeading(IRobot.WEST);

	      if (robot.look(IRobot.AHEAD) == IRobot.WALL) {
	        state = IRobot.WALL;
	        absoluteDirection = "WEST";

	      }	else if (robot.look(IRobot.AHEAD) == IRobot.PASSAGE) {
		    state = IRobot.PASSAGE;
		    absoluteDirection = "WEST";

	      }	else  {
		    state = IRobot.BEENBEFORE;
		    absoluteDirection = "WEST";
	      }

	    }


 	    robot.setHeading(orgHeading);
	    return state;

    }



    //method to direct robot to advance towards target
    private int headingController(IRobot robot) {
	int resultNorth = isTargetNorth(robot);
    int resultEast = isTargetEast(robot);
	//int randnoHead = 0;

	String headingName = "West";
	int resultN = lookHeading(robot, IRobot.NORTH);
	int resultE = lookHeading(robot, IRobot.EAST);
	int resultW = lookHeading(robot, IRobot.SOUTH);
	int resultS = lookHeading(robot, IRobot.WEST);
	int heading = IRobot.WEST;

    // an array where two absolute directions that are clear and lead robot to target (no walls ) are selected out of all four
    //int[] arrayClrTarget = {}

    ArrayList<Integer> arrayClrTarget = new ArrayList<>();
    //int[] arrayClrTarget = {};
    // an array where two absolute directions that are clear and do not lead robot to target are selected (in the case where the two absolute directions that DO lead robot to target are blocked)
    ArrayList<Integer> arrayClrAvailable = new ArrayList<>();

    //CASE 1 - north east
    if (resultNorth == 1 && resultEast == 1) {
        arrayClrTarget.add(IRobot.NORTH);
        arrayClrTarget.add(IRobot.EAST);

        arrayClrAvailable.add(IRobot.SOUTH);
        arrayClrAvailable.add(IRobot.WEST);
        int randnoIndex = (int)(Math.random() * arrayClrTarget.size());

     //case A - both N and E directions lead to a passage (ii): choose randomly between 2 directions
        if (resultN != IRobot.WALL && resultE != IRobot.WALL) {
            randnoIndex =(int)(Math.random() * arrayClrTarget.size());
            heading = arrayClrTarget.get(randnoIndex);
            robot.setHeading(heading);

            //NOT NEEDED - DEBUG
            if (heading == IRobot.NORTH) {
                headingName = "North";
            }

            else if (heading == IRobot.EAST) {
                headingName = "East";
            }

      // case B - N direction leads to a wall but E direction leads to a passage (i): select E direction
      } else if (resultN == IRobot.WALL && resultE != IRobot.WALL) {
            for (int i = 0; i < arrayClrTarget.size(); i++) {
                if (arrayClrTarget.get(i) == IRobot.EAST) {
                    heading = arrayClrTarget.get(i);
                    headingName = "East";
                    robot.setHeading(heading);
                }
            }
       // case C - E direction leads to wall but N direction leads to a passage (i): select N direction
      } else if (resultN != IRobot.WALL && resultE == IRobot.WALL) {;
             for (int i = 0; i < arrayClrTarget.size(); i++) {
                if (arrayClrTarget.get(i) == IRobot.NORTH) {
                    heading = arrayClrTarget.get(i);
                    headingName = "North";
                }
                robot.setHeading(heading);
            }

      // case D - N and E directions both lead to walls (iii) - choose randomly between S and W directions
      } else if (resultN == IRobot.WALL && resultE == IRobot.WALL) {
            do {
                randnoIndex = (int)(Math.random() * arrayClrAvailable.size());
                heading = arrayClrAvailable.get(randnoIndex);

            } while (lookHeading(robot, heading) == IRobot.WALL);
            robot.setHeading(heading);

            if (heading == IRobot.SOUTH) {
                headingName = "South";
            } else if (heading == IRobot.WEST) {
                headingName = "West";
            }

      }



    //CASE 2 - north west
    } else if (resultNorth == 1 && resultEast == -1) {
        arrayClrTarget.add(IRobot.NORTH);
        arrayClrTarget.add(IRobot.WEST);

        arrayClrAvailable.add(IRobot.SOUTH);
        arrayClrAvailable.add(IRobot.EAST);
        int randnoIndex = (int)(Math.random() * arrayClrTarget.size());

        //case A - both N and W directions lead to a passage (ii): choose randomly between 2 directions
        if (resultN != IRobot.WALL && resultW != IRobot.WALL) {
            System.out.println("north and west free");
            randnoIndex =(int)(Math.random() * arrayClrTarget.size());
            heading = arrayClrTarget.get(randnoIndex);
            robot.setHeading(heading);

            //NOT NEEDED - DEBUG
            if (heading == IRobot.NORTH) {
                headingName = "North";
            }

            else if (heading == IRobot.WEST) {
                headingName = "West";
            }

        // case B - N direction leads to a wall but W direction leads to a passage (i): select W direction
        } else if (resultN == IRobot.WALL && resultW != IRobot.WALL) {
            System.out.println("north wall, west free");
            for (int i = 0; i < arrayClrTarget.size(); i++) {
                if (arrayClrTarget.get(i) == IRobot.WEST) {
                    heading = arrayClrTarget.get(i);
                    headingName = "West";
                    robot.setHeading(heading);
                }
            }
        // case C - W direction leads to wall but N direction leads to a passage (i): select N direction
        } else if (resultN != IRobot.WALL && resultW == IRobot.WALL) {
                System.out.println("north free, west wall");
                for (int i = 0; i < arrayClrTarget.size(); i++) {
                if (arrayClrTarget.get(i) == IRobot.NORTH) {
                    heading = arrayClrTarget.get(i);
                    headingName = "North";
                }
                robot.setHeading(heading);
            }

        // case D - N and W directions both lead to walls (iii) - choose randomly between S and E directions
        } else if (resultN == IRobot.WALL && resultW == IRobot.WALL) {
            System.out.println("north and west wall");
            do {
                randnoIndex = (int)(Math.random() * arrayClrAvailable.size());
                heading = arrayClrAvailable.get(randnoIndex);

            } while (lookHeading(robot, heading) == IRobot.WALL);
            robot.setHeading(heading);

            if (heading == IRobot.SOUTH) {
                headingName = "South";
            } else if (heading == IRobot.EAST) {
                headingName = "East";
            }

        }

    }


    //CASE 3 - south east


    //CASE 4 - south west





    // print out to terminal where the robot is heading each time it moves
    System.out.println("Robot will be heading " + headingName + " to reach target");
    return heading;

    }



}

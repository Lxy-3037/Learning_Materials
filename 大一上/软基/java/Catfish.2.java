public class Catfish {

    /**
     * Location of the catfish - which column.
     */
    private int column = 1;

    /**
     * Energy level of catfish
     */
    private int energyLevel = 10;
    private String fileName;
    /**
     * Location of catfish - the column
     *
     * @return - an integer representing the column location of catfish.
     */
    public int getColumn() {
		return column;
	// Student: return the column value

    }

    /**
     * Swim one cell to the right by incrementing the value stored in column by 1.
     */
    public void swimRight() {
		if(column <= 10)
		        {
		            column = column + 1;
		            energyLevel = energyLevel - 1;
		        } else
		        {
		            return;
                }
	// Student: Increment the value stored in column attribute by 1 and
	// decrement the value stored in energyLevel by 1 if the
	// new value of column is less than or equal to 10.

    }

    /**
     * get the image of catfish
     *
     * @return a String indicating the filename of catfish image
     */
    public String getImage() {
		if(energyLevel<5){
		                fileName ="/CatFish-tired.gif";
		                 }
		                 else
		                 {
		                fileName ="/CatFish.gif";
		                 }
             return fileName;
	// Student: return the image filename that represents the catfish
	// The image of a tired catfish (a catfish with energyLevel less than 5)
	// is "/CatFish-tired.gif". files
	// The iamge of a catfish that is not tired is "/CatFish.gif".

    }
}

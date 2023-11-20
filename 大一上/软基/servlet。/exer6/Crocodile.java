import java.util.Vector;
/*
 * Created on Jul 5, 2003
 *
 */

/**
 * Crocodile - simulates a Crocodile - can swim, eat, and consume
 * energy in the process.
 *
 * @author iCarnegie av
 *
 */
public class Crocodile extends LivingBeing {

	/**
	 * The Crocodile is born "alive".
	 * Then it dies, becoming a corpse.
	 */
	private static final String ALIVE = "alive";

	/**
	 * The Crocodile is born "alive".
	 * Then it dies, becoming a "dead" corpse.
	 */
	private static final String DEAD = "dead";


	/**
	 * Energy needed to swim in a block of time.
	 */
	private static final int ENERGY_TO_SWIM = 2;

	/**
	 * debugging level.
	 */
	private static final int DEBUG = 0;

	/**
	 * Energy needed to look for food once.
	 */
	private static final int ENERGY_TO_LOOK_FOR_FOOD = 1;

	/**
	 * Energy expended to eat once.
	 */
	private static final int ENERGY_TO_EAT = 1;

	/**
	 * Energy gained when a full meal is eaten.
	 */
	private static final int ENERGY_IN_A_FULL_MEAL = 10;

	/**
	 * Lowest possible energy needed for a baby to survive.
	 */
	private static final int BABY_MIN_ENERGY = 15;

	/**
	 * Maximum energy that a baby can store.
	 */
	private static final int BABY_MAX_ENERGY = 100;

	/**
	 * For each block of time, the min energy grows by a certain amount
	 */
	private static final int MIN_ENERGY_GROWTH_INCREMENT = 5;

	/**
	 * For each block of time, the max energy grows by a certain amount
	 */
	private static final int MAX_ENERGY_GROWTH_INCREMENT = 10;

	// Concept example: final. since it is a constant
	// Concept example: static. since only one value is needed
	// 						irrespective of number of object instances
	/**
	 * String constant - used to indicate the direction Crocodile is facing.
	 */
	private static final String RIGHT = "right";

	/**
	 * String constant - used to indicate the direction Crocodile is facing.
	 */
	private static final String LEFT = "left";

	/**
	 * String constant - used to indicate the direction Crocodile is facing.
	 */
	private static final String UP = "up";

	/**
	 * String constant - used to indicate the direction Crocodile is facing.
	 */
	private static final String DOWN = "down";

	/**
	 * Name of species
	 */
	private static final String SPECIES = "Crocodile";

	/**
	 * Row-wise location of the Crocodile
	 */
	private int row;

	/**
	 * Column-wise location of the Crocodile
	 */
	private int column;

	/**
	 * Is the Crocodile dead or alive?
	 */
	private String deadOrAlive;

	/**
	 * Amount of energy the Crocodile has.
	 */
	private int energy;

	/**
	 * Age expressed as blocks of time lived
	 */
	private int age = 0;

	/**
	 * Name of this Crocodile.
	 */
	private final String name;

	/**
	 * The simulation to which this Crocodile belongs.
	 * This is needed so the Crocodile can send a message
	 * to simulation and ask
	 * for prey (or predator) in the neighboring locations.
	 * Prey is food. Food is good!
	 */
	private Simulation simulation;

	/**
	 * Minimum energy level needed to survive.
	 * The minimum could increase as the individual grows.
	 */
	private int minEnergy;

	/**
	 * Maximum energy level that the Crocodile could carry.
	 * The maximum could change as the individual grows.
	 */
	private int maxEnergy;

	/**
	 * Which direction am I facing.
	 */
	private String direction;

	/**
	 *
	 * Number of Crocodile created
	 */
	private static int nCrocodileCreated = 0;

	/**
	 * Constructor. Initialize an algae to start life at a specified
	 * location with a specified energy. If location is out of bounds,
	 * locate the Crocodile at the nearest edge.
	 *
	 * @param initialRow - the row at which the Crocodile is located
	 * @param initialColumn - the column at which the Crocodile is located
	 * @param initialSimulation - the simulation that the Crocodile belongs to
	 */
	public Crocodile(
		int initialRow,
		int initialColumn,
		Simulation initialSimulation) {

			name = SPECIES + nCrocodileCreated;
	}

	/**
	 * Get the row at which the Crocodile is located
	 *
	 * @return - the row of the Crocodile's location.
	 */
	public int getRow() {
		return row;
	}

	/**
	 * Get the column at which the Crocodile is located
	 *
	 * @return - the column of the Crocodile's location.
	 */
	public int getColumn() {
		return column;
	}

	/**
	 * Get the Crocodile's age
	 *
	 * @return the age of the Crocodile expressed in blocks of time
	 */
	public int getAge() {
		return age;
	}

	/**
	 * Color of the Crocodile expressed in hex notation.
	 * For example, the "green-est" color is "#00FF00",
	 * "blue-est" is "#0000FF", the "red-est" is "#FF0000".
	 *
	 * @return the rgb color in hex notation. preceded by a pound character '#'
	 */
	public String getColor() {
		return "#FFFFFF"; // default is white.
	}

	/**
	 * Get the name of this Crocodile
	 *
	 * @return the name of the Crocodile.
	 */
	public String getName() {
		return name;
	}

	/**
	 * Get the minimum energy needed to live.
	 *
	 * @return the minimum energy needed for the Crocodile to live.
	 */
	private int getMinEnergy() {
		return minEnergy;
	}

	/**
	 * get the maximum energy that the Crocodile can carry.
	 *
	 * @return the maximum energy the Crocodile can carry.
	 */
	private int getMaxEnergy() {
		return maxEnergy;
	}


	/**
	 * Get the energy currently carried by the Crocodile.
	 *
	 * @return current energy level of the organism
	 */
	public int getEnergy() {
		return energy;
	}

	/**
	 * Sets energy level.
	 * If new energy level is less than minimum energy level, the organism dies.
	 * New energy level is capped at maximum energy level.
	 */
	private void setEnergy(int newEnergy) {

	}

	/**
	 * Die: Change the deadOrAlive to DEAD.
	 */
	public void die() {
		deadOrAlive = DEAD;
	}

	/**
	 * Is the Crocodile dead?
	 *
	 * @return <code>true</code> if dead. <code>false</code>, otherwise.
	 */
	public boolean isDead() {
		return (deadOrAlive == DEAD);
	}

	/**
	 * Get the direction faced by the Crocodile.
	 *
	 * @return the facing direction.
	 */
	private String getDirection() {
		return direction;
	}

	/**
	 * Is the Crocodile hungry?
	 *
	 * @return True, if hungry. False, otherwise.
	 */
	private boolean isHungry() {

		// Hungry, if current energy level is less than twice the
		// amount needed for survival.
		return false;
	}

	/**
	 * Move the Crocodile to a new row, if new row is within lake bounds.
	 *
	 * @param newRow - the row to move to.
	 * @return the row moved to. Lake boundary limits movement.
	 */
	private int moveToRow(int newRow) {

		return row;
	}

	/**
	 * Move the Crocodile to a new column, if new column is within lake bounds.
	 *
	 * @param newColumn - the column to move to.
	 * @return the column moved to. Lake boundary limits movement.
	 */
	private int moveToColumn(int newColumn) {

		return column;
	}

	/**
	 * This individual belongs to the Crocodile species.
	 *
	 * @return The string indicating the species
	 */
	public String getSpecies() {
		return SPECIES;
	}

	/**
	 * Crocodile should be displayed as an image.
	 *
	 * @return a constant defined in {@link Simulation#IMAGE Simulation} class
	 */
	public String getDisplayMechanism() {
		return Simulation.IMAGE;
	}

	/**
	 * Get the image of the Crocodile
	 *
	 * @return filename of Crocodile image
	 */
	public String getImage() {

		return "Crocodile-right.gif";
	}


	/**
	 * Look for food in the neighborhood. Consume some energy in the process.
	 *
	 * @return a neighboring algae that is food.
	 */
	private AlgaeColony lookForFoodInNeighborhood() {

		return null;
	}


	/**
	 * Swim to a new location if possible.
	 * Consumes some energy.
	 */
    private void swimIfPossible() {

	}




	/**
	 * Eat food if available.
	 *
	 */
     private void eatIfPossible() {

	}
	/**
	 * Crocodile lives its life. It may lose or gain energy.
	 */
	public void liveALittle() {

	}

}
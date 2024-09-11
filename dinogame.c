// C Program for Dino Game 
#include <conio.h> 
#include <stdio.h> 
#include <time.h> 
#include <windows.h> 

// Function to set the console cursor position 
void moveTo(int x, int y) 
{ 
	COORD coord; 
	coord.X = x; 
	coord.Y = y; 
	SetConsoleCursorPosition( 
		GetStdHandle(STD_OUTPUT_HANDLE), coord); 
} 

// Function to pause execution for a given number of 
// milliseconds 
void pause(unsigned int milliseconds) 
{ 
	clock_t goal = milliseconds + clock(); 
	while (goal > clock()) 
		; 
} 

// Function to display game information on the console 
void displayGameInfo() 
{ 
	system("cls"); 
	moveTo(10, 2); 
	printf("Press X to Exit, Press Space to Jump"); 
	moveTo(62, 2); 
	printf("SCORE : "); 
	moveTo(1, 25); 
	for (int x = 0; x < 79; x++) 
		printf("п"); 
} 

// Global variables for jump height and game speed 
int jumpHeight, gameSpeed = 40; 

// Function to display the character on the console 
void displayCharacter(int jumpType = 0) 
{ 
	static int animationState = 1; 

	// Update the jump height based on the jump type 
	if (jumpType == 0) 
		jumpHeight = 0; 
	else if (jumpType == 2) 
		jumpHeight--; 
	else
		jumpHeight++; 

	// Display the character at the specified position 
	moveTo(2, 15 - jumpHeight); 
	printf("			 "); 
	moveTo(2, 16 - jumpHeight); 
	printf("	 мллл	 "); 
	moveTo(2, 17 - jumpHeight); 
	printf(" ллллллл	 "); 
	moveTo(2, 18 - jumpHeight); 
	printf(" ллллллллл "); 
	moveTo(2, 19 - jumpHeight); 
	printf(" лллллплллл "); 
	moveTo(2, 20 - jumpHeight); 
	printf(" млллллппллллм "); 
	moveTo(2, 21 - jumpHeight); 
	printf(" ллллллпплллллл "); 
	moveTo(2, 22 - jumpHeight); 
	printf(" пллллллппллллп "); 
	moveTo(2, 23 - jumpHeight); 
	if (jumpType == 1 || jumpType == 2) { 
		printf(" ллп плпппл "); 
		moveTo(2, 24 - jumpHeight); 
		printf(" лм лм	 "); 
	} 
	else if (animationState == 1) { 
		printf(" пллп ппп	 "); 
		moveTo(2, 24 - jumpHeight); 
		printf("	 лм		 "); 
		animationState = 2; 
	} 
	else if (animationState == 2) { 
		printf(" плм пл	 "); 
		moveTo(2, 24 - jumpHeight); 
		printf("		 лм	 "); 
		animationState = 1; 
	} 

	moveTo(2, 25 - jumpHeight); 
	if (jumpType != 0) { 
		printf("			 "); 
	} 
	else { 
		printf("ппппппппппппппппп"); 
	} 
	pause(gameSpeed); 
} 

// Function to display the obstacle on the console 
void displayObstacle() 
{ 
	static int obstaclePosition = 0, score = 0; 

	// Check for collision with the obstacle 
	if (obstaclePosition == 56 && jumpHeight < 4) { 
		score = 0; 
		gameSpeed = 40; 
		moveTo(36, 8); 
		printf("Game Over"); 
		getch(); 
		moveTo(36, 8); 
		printf("		 "); 
	} 

	// Display the obstacle at the specified position 
	moveTo(74 - obstaclePosition, 20); 
	printf("л л "); 
	// ... (rest of the obstacle display) 

	// Update obstacle position and score 
	obstaclePosition++; 
	if (obstaclePosition == 73) { 
		obstaclePosition = 0; 
		score++; 
		moveTo(70, 2); 
		printf("	 "); 
		moveTo(70, 2); 
		printf("%d", score); 
		if (gameSpeed > 20) 
			gameSpeed--; 
	} 
} 

// Main function 
int main() 
{ 
	// Set console mode and initialize variables 
	system("mode con: lines=29 cols=82"); 
	char input; 
	int i; 
	displayGameInfo(); 

	// Game loop 
	while (true) { 
		// Continuous display of character and obstacle 
		// until a key is pressed 
		while (!kbhit()) { 
			displayCharacter(); 
			displayObstacle(); 
		} 

		// Handle user input 
		input = getch(); 
		if (input == ' ') { 
			// Jump animation when the space key is pressed 
			for (i = 0; i < 10; i++) { 
				displayCharacter(1); 
				displayObstacle(); 
			} 
			for (i = 0; i < 10; i++) { 
				displayCharacter(2); 
				displayObstacle(); 
			} 
		} 
		else if (input == 'x') { 
			// Exit the game if the 'X' key is pressed 
			return (0); 
		} 
	} 

	return 0; 
}

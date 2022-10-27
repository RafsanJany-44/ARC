"""
File: crapsgui.py
Project 9.7
Pops up a window that allows the user to play the game of craps.
"""

from breezypythongui import EasyFrame
from tkinter import PhotoImage
from craps import Player

class CrapsGUI(EasyFrame):
   
    def __init__(self):
        """Creates the player, and sets up the Images and labels for the two dice to be displayed, the text area for the game state, and the two command buttons."""
        EasyFrame.__init__(self, title = "Craps Game")
        self.setSize(220, 320)
        """Instantiate the model and initial values of the dice"""
        # self.player
        # self.v1
        # self.v2
        """Add labels and buttons to the view"""
        # self.dieLabel1
        # self.dieLabel2
        # self.stateArea
        # self.rollButton
        # self.addButton
        self.refreshImages()

    def nextRoll(self):
        """Rolls the dice and updates the view with
        the results."""
        # Add your code here
            
    def newGame(self):
        """Create a new craps game and updates the view."""
        # Add your code here
        
    def refreshImages(self):
        """Updates the images in the window."""
        # Add your code here

def main():
    CrapsGUI().mainloop()

if __name__ == "__main__":
    main()

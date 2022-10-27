"""
File: die.py

This module defines the Die class.
"""

from random import randint

class Die:
    """This class represents a six-sided die."""

    def __init__(self):
        """Creates a new die with a value of 1."""
        self.value = 1

    def roll(self):
        """Resets the die's value to a random number
        between 1 and 6."""
        self.value = randint(1, 6)

    def getValue(self):
        """Returns the value of the die's top face."""
        return self.value

    def __str__(self):
        """Returns the string rep of the die."""
        return str(self.getValue())

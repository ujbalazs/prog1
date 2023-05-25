import random


# GAME BASE CLASS
class Game:
    def legal_steps(self, state):
        """Steps that can be made in given state."""
        raise NotImplementedError()

    def take_step(self, step, state):  # NOQA
        """Result of taking step in given state."""
        raise NotImplementedError

    def goodness(self, state, player):
        """Goodness measure of the state for the player."""
        raise NotImplementedError()

    def is_leaf(self, state):
        """Is the node a terminal node."""
        return not self.legal_steps(state)

    def next(self, state):
        """Return next player."""
        return state['next']

    def print(self, state):
        """Print current state."""
        print(state)

    def next_state(self, state):
        """Return next (step, state) list."""
        return [(step, self.take_step(step, state))
                for step in self.legal_steps(state)]

    def __repr__(self):
        """Print the name of the game."""
        return '<%s>' % self.__class__.__name__
def gather_positions_and_neighbors(n):
    positions_with_neighbors = []

    for i in range(1, n+1):
        for j in range(1, n+1):
            position = (i, j)
            possible_neighbors = [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]

            for neighbor in possible_neighbors:
                x, y = neighbor
                if 1 <= x <= n and 1 <= y <= n:
                    positions_with_neighbors.append([position, neighbor])
                

    return positions_with_neighbors

class PirosKek(Game):

    def __init__(self,n):
        """Base of the game"""
        self.n=n
        steps=gather_positions_and_neighbors(4)
        board = {(1,1): 'K', (1,2): 'K', (1,3): 'K', (1,4): 'K', (2,1): 'U', (2,2): 'U', (2,3): 'U', (2,4): 'U', (3,1): 'U', (3,2): 'U', (3,3): 'U', (3,4): 'U', (4,1): 'P', (4,2): 'P', (4,3): 'P', (4,4): 'P',}
        
        
                
                
        self.initial = {'next': 'P','result': 0,'board': board,'steps': steps}


    def legal_steps(self, state):
        l = []
        for n in state["steps"]:
            if (state["board"][n[0]] == 'P' or state["board"][n[0]] == 'K') and state["board"][n[1]] == "U":
                    l.append(n)

        return l                 
                    

    def take_step(self, step, state):
        """Effect of the step"""
        if step not in state['steps']:
            return state
        board = state['board'].copy()
        board[step[1]] = state['next']
        board[step[0]] = 'U'
        steps = list(state['steps'])
        return {
            'next': 'K' if state['next'] == 'P' else 'P',
            'result': self.result(board, step, state['next']),  # need to change
            'board': board,
            'steps': steps
        }

    def result(self, board, step, player):
        """If K wins with this step then return 1. If P wins with this then return -1. Else return 0."""
        if self.check(board, step, player):
            return 1 if player == 'K' else -1
        return 0

    def check(self, board, step, player):
        if player=='K':
            if(board[(4,1)]== 'K' and board[(4,2)]== 'K' and board[(4,3)]== 'K' and board[(4,4)]== 'K'):
                return True
            else:
                return False
        else:
            if(board[(1,1)]== 'P' and board[(1,2)]== 'P' and board[(1,3)]== 'P' and board[(1,4)]== 'P'):
                return True
            else:
                return False

    def goodness(self, state, player):
        """X goodness: 1, if it wins; -1, if it loses, 0 if draw."""
        return state['result'] if player == "K" else -state['result']

    def is_leaf(self, state):
        """If someone won or the table is full it will be the end of the game."""
        return state['result'] != 0 or len(state['steps']) == 0

    def print(self, state):
        """Let's see the current state."""
        board = state['board']
        for x in range(1, 4 + 1):
            for y in range(1, 4 + 1):
                print(board.get((x, y), '.'), end=" ")
            print()
        print('Result of the game: ', state['result'])
        print()


# PLAYERS
def random_player(game, state):
    """Randomly choose between options"""
    return random.choice(game.legal_steps(state))




def play_game(game, *players):
    state = game.initial
    game.print(state)
    while True:
        for player in players:
            step = player(game, state)
            state = game.take_step(step, state)
            game.print(state)
            if game.is_leaf(state):
                game.print(state)
                end_result = game.goodness(state, 'K')
                return "K wins" if end_result == 1 else "P wins" if end_result == -1 else "Draw"


tto = PirosKek(4)

# Test if playing works
play_game(tto, random_player, random_player)

# Demonstrate the power of the search algorithms
# you can comment out the game.print(state) lines in the play_game function for this



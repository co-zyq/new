#简单起见，我们的扑克只有52张牌（没有大小王），
#游戏需要将 52 张牌发到 4 个玩家的手上，
#每个玩家手上有 13 张牌，
#按照黑桃、红心、草花、方块的顺序和点数从小到大排列，
#暂时不实现其他的功能
import random
from enum import Enum


class Color(Enum):
    SPADE = 0
    HEART = 1
    CLUB = 2
    DIAMOND = 3
class Card:
    def __init__(self,color,number):
        self.color = color
        self.number = number

    def __repr__(self):
        color='♠♥♣♦'
        number = ['', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']
        return f'{color[self.color.value]}{number[self.number]}' 


class Poker:
    def __init__(self):
        self.cards = [Card(color,number)
                     for color in Color
                     for number in range(1,14)]
        self.current = 0
    def shuffle(self):#洗牌
        self.current = 0
        random.shuffle(self.cards)
    def deal(self):#发牌
        card = self.cards[self.current]
        self.current += 1
        return card
    @property
    def has_next(self):
        return self.current < len(self.cards)

#poker = Poker()
#print(poker.cards)  # 洗牌前的牌
#poker.shuffle()
#print(poker.cards)  # 洗牌后的牌


class Player:
    def __init__(self,name):
        self.name = name
        self.cards = []

    def add_card(self,card):
        self.cards.append(card)

    def arrange(self):
        self.cards.sort()


poker = Poker()
poker.shuffle()
players = [Player('东邪'), Player('西毒'), Player('南帝'), Player('北丐')]
for _ in range(13):
    for player in players:
        player.add_card(poker.deal())
for player in players:
    player.arrange()
    print(f'{player.name}:',end=' ')
    print(player.cards)
    



#6666
#7777
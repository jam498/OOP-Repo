#include <iostream>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <time.h>

using std::vector;
using std::stack;

enum Suit {
	Spades,
	Clubs,
	Hearts,
	Diamonds
};
enum Rank {
	Ace,
	Two, Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
};

struct Card
{
	Suit suit;
	Rank rank;
};
std::ostream& operator<<(std::ostream& os, Rank r) {
	switch (r)
	{
	case(Ace) : os << "Ace";
		break;
	case(Two) : os << "Two";
		break;
	case(Three) : os << "Three";
		break;
	case(Four) : os << "Four";
		break;
	case(Five) : os << "Five";
		break;
	case(Six) : os << "Six";
		break;
	case(Seven) : os << "Seven";
		break;
	case(Eight) : os << "Eight";
		break;
	case(Nine) : os << "Nine";
		break;
	case(Ten) : os << "Ten";
		break;
	case(Jack) : os << "Jack";
		break;
	case(Queen) : os << "Queen";
		break;
	case(King) : os << "King";
		break;
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, Suit s) {
	switch (s)
	{
	case(Spades) : os << "Spades";
		break;
	case(Clubs) : os << "Clubs";
		break;
	case(Hearts) : os << "Hearts";
		break;
	case(Diamonds) : os << "Diamonds";
		break;
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, Card c) {
	os << c.rank << " of " << c.suit;
	return os;
}

void buildDecks(stack<Card>&, stack<Card>&);
void war(stack<Card>, stack<Card>);

int main()
{
	stack<Card> p1;
	stack<Card> p2;
	srand(time(NULL));

	buildDecks(p1, p2);
	war(p1, p2);
	return 0;
}

void buildDecks(stack<Card>& p1, stack<Card>&p2)
{
	vector<Card> deck;
	int divide;
	Card temp;
	for (int s = 0; s < 4; s++)
	{
		temp.suit = static_cast<Suit>(s);
		for (int r = 0; r < 13; r++)
		{
			temp.rank = static_cast<Rank>(r);
			deck.push_back(temp);
		}
	}

	for (int k = 52; k > 1; k--)
	{
		divide = rand() % (k - 1);
		if (k % 2 == 0)
			p1.push(deck[divide]);
		else
			p2.push(deck[divide]);
		deck.erase(deck.begin() + divide);
	}
	p2.push(deck[0]);
}

void war(stack<Card> p1, stack<Card>p2)
{
	int player1 = 0, player2 = 0;
	for (int i = 0; i < 26; i++)
	{
		if (static_cast<int>(p1.top().rank) > static_cast<int>(p2.top().rank))
		{
			player1++;
			std::cout << p1.top() << "beats " << p2.top() << ", Point to Player 1\n";
		}
		else if (static_cast<int>(p1.top().rank) < static_cast<int>(p2.top().rank))
		{
			player2++;
			std::cout << p2.top() << " beats " << p1.top() << ", Point to Player 2\n";
		}
		p1.pop();
		p2.pop();
	}
	if (player1 > player2)
		std::cout << "Player 1 wins";
	if (player1 < player2)
		std::cout << "Player 2 wins";
}

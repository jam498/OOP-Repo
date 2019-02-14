#include <iostream>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <random>


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
	Two,
	Three,
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
	unsigned char data;
	Card() = default;
	Card(Rank r, Suit s)
		: data(static_cast<unsigned>(s) << 4 | static_cast<unsigned>(r))
	{ }
	Suit get_Suit() const { return static_cast<Suit>(data >> 4 ); };
	Rank get_Rank() const { return static_cast<Rank>(data & 0xf); };
	//Suit suit;
	//Rank rank;
};

std::ostream& operator<<(std::ostream& os, Rank r) {
	switch (r)
	{
    case(Ace) : return os << "A";
	case(Two) : return os << "2";
	case(Three) : return os << "3";
	case(Four) : return os << "4";
	case(Five) : return os << "5";
	case(Six) : return os << "6";
	case(Seven) : return os << "7";
	case(Eight) : return os << "8";
	case(Nine) : return os << "9";
	case(Ten) : return os << "10";
	case(Jack) : return os << "J";
	case(Queen) : return os << "Q";
	case(King) : return os << "K";
	}
}

std::ostream& operator<<(std::ostream& os, Suit s) {
	switch (s)
	{
	case(Spades) : return os << "S";
	case(Clubs) : return os << "C";
	case(Hearts) : return os << "H";
	case(Diamonds) : return os << "D";
	}
}

std::ostream& operator<<(std::ostream& os, Card c) {
	return os << c.get_Rank() << c.get_Suit();
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
		for (int r = 0; r < 13; r++)
		{
			temp = Card(static_cast<Rank>(r), static_cast<Suit>(s));
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
		if (static_cast<int>(p1.top().get_Rank()) > static_cast<int>(p2.top().get_Rank()))
		{
			player1++;
			std::cout << p1.top() << " beats " << p2.top() << ", Point to Player 1\n";
		}
		else if (static_cast<int>(p1.top().get_Rank()) < static_cast<int>(p2.top().get_Rank()))
		{
			player2++;
			std::cout << p1.top() << " beats " << p2.top() << ", Point to Player 2\n";
		}
		p1.pop();
		p2.pop();
	}
	if (player1 > player2)
		std::cout << "Player 1 wins";
	if (player1 < player2)
		std::cout << "Player 2 wins";
}

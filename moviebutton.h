#pragma once
#include "button.h"
#include <list>
class moviebutton : public button
{
protected:
	int num;
public:
	void setNum(int x) { num = x; }
	int getNum() { return num; }
	void draw(int num);
	void update(int i);
	bool contains(float x, float y, float cx, float cy, float width, float height);
	moviebutton();
	std::list<int> movieYear(int year);
	std::list<int> movieGenre(std::string gen);
	std::string movieNames[18] = { "A Mermaid Tale", "Fairytopia: Mermaidia","The Pearl Princess",
		"Mariposa","Fairytopia","Thumbelina","The Princess and the Pauper",
		"The Magic of Pegasus","The Island Princess","Rapunzel","Swan Lake",
		"The Three Musketeers","The Barbie Diaries","A Fashion Fairytale","The Pink Shoes","The Nutcracker",
		"A Perfect Christmas","A Christmas Carol" };
	int prodYears[18] = { 2010,2006,2014,2008,2005,2009,2004,2005,2007,2002,2003,2008,2006,2010,2013,2001,2011,2008 };
	std::string genre[18] = { "mermaids","mermaids","mermaids","fairies","fairies","fairies","princesses","princesses","princesses",
		"reimagined classics", "reimagined classics", "reimagined classics" ,"modern day","modern day","modern day","christmas joy",
		"christmas joy","christmas joy" };
	std::string directors[18] = { "Adam L.Wood", "William Lau","Ezekiel Norton","Conrad Helten","Walter P. Martishius, Will Lau",
		"Conrad Helten","William Lau","Greg Richardson","Greg Richardson","Owen Hurley","Owen Hurley","William Lau","Eric Fogel",
		"William Lau","Owen Hurley","Owen Hurley","Mark Baldo","William Lau" };
	std::string writers[18] = { "Elise Allen","Elise Allen","Cydne Clark, Steve Granat","Elise Allen","Elise Allen, Diane Duane",
		"based on \"Thumbelina\" by Hans Christian Andersen","Cliff Ruby, Elana Lesser","Ruth Handler","Elana Lesser, Cliff Ruby",
		"Elana Lesser, Cliff Ruby","Elana Lesser, Cliff Ruby", "Amy Wolfram","Elise Allen, Laura McCreary",
		"Elise Allen","Alison Taylor","Linda Engelsiepen, Hilary Hinkle, Rob Hudnut","Elise Allen","Elise Allen" };
	std::string voiceActors[18][2] =
	{ "Kelly Sheridan, Kathleen Barr,",
	"Tabitha St.Germain",
	"Kelly Sheridan, Lee Tockar,",
	"Christopher Gaze",
	"Kelly Sheridan, Katie Crown,",
	"Mark Oliver",
	"Chiara Zanni, Tabitha St. Germain,",
	"Kathleen Barr",
	"Kelly Sheridan, Lee Tockar,",
	"Tabitha St.Germain",
	"Kelly Sheridan, Anna Cummer",
	"",
	"Kelly Sheridan, Mark Hildreth,",
	"Alessandro Juliani",
	"Kelly Sheridan, Kathleen Barr,",
	"Lalainia Lindbjerg",
	"Kelly Sheridan, Melissa Lyons,",
	"Alessandro Juliani",
	"Kelly Sheridan, Anjelica Huston,",
	"Cree Summer",
	"Kelly Sheridan, Mark Hildreth,",
	"Kelsey Grammer",
	"Kelly Sheridan, Tim Curry,",
	"Kira Tozer",
	"Kelly Sheridan, Sarah Edmondson,",
	"Venus Terzo",
	"Diana Kaarina, Adrian Petriw,",
	"Tabitha St.Germain",
	"Kelly Sheridan, Katie Crown,",
	"Ali Liebert",
	"Kelly Sheridan, Kirby Morrow,",
	"Tim Curry",
	"Diana Kaarina, Jennifer Waris,",
	"Rachel Drance",
	"Morwenna Banks, Kathleen Barr,",
	"Kelly Sheridan" };
	std::string descriptions[18][6] =
	{ "Merlia gets the best of both worlds in this",
	"tale of self discovery in the mermaid filled",
	"depths of the Pacific ocean off the coast of",
	"Malibu where she surfs professionally. By day,",
	"as by night she is the princess of the mermaids",
	"who she saves from her evil aunt.",

	"A tale of tragic sacrifice as Elina trades her",
	"wings for a tail to save her merman friend Nalu.",
	"Nalu is kidnnaped but an evil queen who thinks",
	"he holds the key to free her from her exile. Be",
	"prepared for a sassy i-hate-everyone sidekick",
	"and well dressed gremlins.",

	"Riding the Merlia-success train, this Rapunzel",
	"knockoff follows Lumina, a girl with magic",
	"abilities (but not magic hair surprisingly) ",
	"who lives in a secluded cave with her over",
	"protective mother and discovers she is a princess.",
	"Could have been called Rapunzel with a tail.",

	"In the epitome of 'for the night is dark and",
	"full of terrors', Mariposa is an avid reader",
	"who ventures beyond the protection of the ",
	"magic lights that keep her people safe.",
	"Granted she did it to save the aforementioned ",
	"lights but George Martin did it first I'm sorry.",

	"An ode to the rainbow if there ever was one.",
	"Elina, a spurned wingless fairy embarks on a",
	"journey to save her realm's protectors from the",
	"evil cluches of Laverna, the queen's evil ",
	"sister.And she receives better wings than the ",
	"ones her bullies had.Heroism rewards well, kids.",

	"In this dark tale of kidnnaping and slavery,",
	"Thumbelina, a tiny fairy living in a fairy",
	"flowers village ends up in th bedroom of spoiled",
	"preteen McKenzie who is going through a rough ",
	"puberty and makes thumbelina her slave. Will ",
	"she manage to escape and save her village ? ",

	"A tale where a bored princess and a tired ",
	"seamstress who oh so luckily look exactly the ",
	"same but with different hair colors swap lives.",
	"Guess who landed in reality the roughest. Note ",
	"that this story also has an adventurous side",
	"as they also save the kingdom for a madman",

	"In the most confusing movie of the franchise,",
	"it's Annika and her ice skates against the",
	"world .Maybe not the world but certainly an ",
	"evil wizard who turns her parents into stone ",
	"and wants to  marry her sister who's a pegasus",
	"Watch for the winter magic and the polar bear",

	"After a shipwreck a girl ends up on an ",
	"abandoned island where a handsome prince finds ",
	"her and wants to marry her. But lo and behold.",
	"His royal parents want to marry him to a lovely ",
	"girl who doesn't have a strangely protective  ",
	"elephant for a friend.Lfe really is that cruel.",

	"An intricate web of lies threatens to drown ",
	"Rapunzel as she discovers her true heritage from",
	"a magic brush her parents left her. But don't ",
	"think mother Gothel will let that slide, no no no. ",
	"She and her dragon trap her in her tower.Will ",
	"she manage to find the perfect dress and escape? ",

	"Odette, the daughter of a humble baker follows ",
	"a unicorn into the enchanted forest (as one does) ",
	"and, caught in the crossfires of an evil wizard's  ",
	"spell, turns into a swan. Will she win the prince ",
	"break the spell, free herself or will Odille, the ",
	"wizard's daughter get everything she ever wanted?",

	"Corinne, a girl who can't take a step without ",
	"tripping but can land a triple flip on a banister, ",
	"goes to Paris to make her luck as a musketeer. The",
	"patriarchy is against her but she does it anyway.",
	"While doing that she discovers a plot to kill the ",
	"prince and she saves him with her usual finesse ",

	"Barbie gets a diary with a matching bracelet that ",
	"grant wishes But when she loses the bracelet she ",
	"must figure out whether it's the bracelet or her ",
	"spark that actually helps her succeed while also",
	" suffering the usual afflictions of high school ",
	"(mean girls, crushes). That's a toughie folks.",

	"Barbie thinks her boyfriend cheated on her so she ",
	"goes to Paris to her auntie and her dying fashion ",
	"house.Looking for a hobby she decides to save the  ",
	"store with the help of three fairies that appear ",
	"at just the right time. And of course there's an ",
	"evil fashion antagonist with a silly sidekick.",

	"A ballerina who thinks she is better than she is",
	"puts on some magic ballet shoes and transports to ",
	"a the lion the witch and the wardrobe kinda place",
	"but with ballet where she realises that even",
	"protagonists have troubles. The first Barbie movie ",
	"to teach that being perfect isn't easy but it's cool.",

	"Clara receives a nutcracker for christmas. People ",
	"really know what girls want! Then she shrinks ",
	"to the size of the nutcracker and goes to a magic ",
	"realm to try and break the spell. Talk about a ",
	"Christmas to remember in this tale of gravity ",
	"defying ballet and eerily unmoving hair.",

	"Barbie and her sisters have some pretty big ",
	"Christmas plans but on their way there they get ",
	"stranded on a small town. Will they let this",
	"change of plans ruin their holidays? Given",
	"Barbie's track record I'm willing to bet no.",
	"Watch and find out how Barbie saves Christmas!",

	"Eden is a diva opera singer in Victorian ",
	"London who forgets who she is so she is ",
	"visited by three ghosts: the past ghost, the ",
	"present ghost and the future ghost. Through a ",
	"series of teleportations Eden learns to love ",
	"the magic of Christmas and her humble roots." };
};
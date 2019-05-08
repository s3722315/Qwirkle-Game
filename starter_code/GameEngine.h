

class GameEngine {
  private:
    Tile** board;
    Player players[2];
    Bag tileBag;
  public:
    GameEngine(Player player1, Player player2);

    void ExpandBoard();

    bool placePiece(int playerNum, Tile placedTile, char yPos, int xPos);

    bool replacePiece(int playerNum, Tile replacedTile);

    bool checkGameOver();

    void endGame(bool gameEnded);
}

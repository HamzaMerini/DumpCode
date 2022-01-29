  std::ifstream f("welcome.txt");

    if (f.is_open()){
        cout << f.rdbuf();
}

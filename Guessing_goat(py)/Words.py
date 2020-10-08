class Word:
    def __init__(self, rand_num, lim):        #constructor
        self.rand_num = rand_num
        self.lim = lim

    def the_word(self):
        i = self.rand_num
        list = {

            1:  "friday",
            2:  "mike",
            3:  "milk",
            4:  "shark",
            5:  "even",
            6:  "cat",
            7:  "lion",
            8:  "dog",
            9:  "hen",
            10: "pizza",
            11: "cola",
            12: "book",
            13: "duck",
            14: "ball",
            15: "10",
            16: "c",
            17: "java",
            18: "python",
            19: 'blue',
            20: 'red',
            21: 'sky',
            22: 'mac',
            23: 'net',
            24: 'get',
            25: '666',
            26: 'easy',
            27: 'bad',
            28: 'frog',
            29: 'like',
            30: 'jack'

        }

        return list.get(i, "Limit Crossed")

    def pri(self):
        l = {

            1:  "friday",
            2:  "mike",
            3:  "milk",
            4:  "shark",
            5:  "even",
            6:  "cat",
            7:  "lion",
            8:  "dog",
            9:  "hen",
            10: "pizza",
            11: "cola",
            12: "book",
            13: "duck",
            14: "ball",
            15: "10",
            16: "c",
            17: "java",
            18: "python",
            19: 'blue',
            20: 'red',
            21: 'sky',
            22: 'mac',
            23: 'net',
            24: 'get',
            25: '666',
            26: 'easy',
            27: 'bad',
            28: 'frog',
            29: 'like',
            30: 'jack'

        }
        j=1
        while j <= self.lim:
            print(l[j])
            j = j + 1


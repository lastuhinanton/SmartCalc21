#ifndef SRC_MODEL_H_
#define SRC_MODEL_H_

namespace s21 {

    
    class Model
    {
        public:
            Model() {}
            ~Model() {}
            void getValueFromExpressionForGraph(char *str, double X);

        private:
            double data;
    };

}

#endif  // SRC_MODEL_H_

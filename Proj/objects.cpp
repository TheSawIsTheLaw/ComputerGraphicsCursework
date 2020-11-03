#include "objects.hpp"
#include <QDebug>

#include "config.hpp"

const Dot3D &Vertex::getPosition() const { return position; }

void Vertex::setPosition(Dot3D &position_) { position = position_; }

const std::vector<size_t> Vertex::getUsedFacets() { return usedFacets; } // Changeable?

void Vertex::setUsedFacets(std::vector<size_t> usedFacets_) { usedFacets = usedFacets_; }

const std::vector<size_t> Facet::getUsedDots() { return usedDots; }

void Facet::setUsedDots(std::vector<size_t> usedDots_) { usedDots = usedDots_; }

const std::vector<Vertex> PolModel::getVertices() { return vertices; }

void PolModel::setVertices(std::vector<Vertex> &vertices_) { vertices = vertices_; }

const std::vector<Facet> PolModel::getFacets() { return facets; }

void PolModel::setFacets(std::vector<Facet> facets_) { facets = facets_; }

const Dot3D &Illuminant::getPosition() { return position; }

void Illuminant::setPosition(Dot3D &position_) { position = position_; }

const MathVec &Illuminant::getVector() { return vector; }

void Illuminant::setVector(MathVec &vector_) { vector = vector_; }

CellScene::CellScene() {}

CellScene::CellScene(size_t width_, size_t height_)
{
    width = width_;
    height = height_;

    for (size_t i = 0; i < height_; i++)
    {
        cells.push_back(std::vector<bool>(width_));
        for (size_t j = 0; j < width_; j++) cells[i][j] = true;
    }

    modelsNum = 0;
    illumNum = 0;

    transMatrix << 1, 0, 0, 0,
                   0, 1, 0, 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1;
}

size_t CellScene::getWidth() { return width; }

size_t CellScene::getHeight() { return height; }

CellScene::operator bool() const { return this->plateModel; }

void CellScene::moveUp(double value)
{
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, 0,
               0, 1, 0, -value,
               0, 0, 1, 0,
               0, 0, 0, 1;

    transMatrix *= moveMat;
//    centerDot.move(0, -value, 0);

//    Dot3D curDot;
//    std::vector<Vertex> vertices = plateModel->getVertices();
//    for (std::vector<Vertex>::iterator iter = vertices.begin(); iter != vertices.end();
//         iter++)
//    {
//        curDot = iter->getPosition();
//        curDot.move(0, -value, 0);
//        iter->setPosition(curDot);
//    }
//    plateModel->setVertices(vertices);

//    for (size_t i = 0; i < modelsNum; i++)
//    {
//        vertices = models.at(i).getVertices();
//        for (std::vector<Vertex>::iterator iter = vertices.begin(); iter != vertices.end();
//             iter++)
//        {
//            curDot = iter->getPosition();
//            curDot.move(0, -value, 0);
//            iter->setPosition(curDot);
//        }

//        models.at(i).setVertices(vertices);
//    }
}

void CellScene::moveDown(double value)
{
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, 0,
        0, 1, 0, value,
        0, 0, 1, 0,
        0, 0, 0, 1;

    transMatrix *= moveMat;
//    centerDot.move(0, value, 0);

//    Dot3D curDot;
//    std::vector<Vertex> vertices = plateModel->getVertices();
//    for (std::vector<Vertex>::iterator iter = vertices.begin(); iter != vertices.end();
//         iter++)
//    {
//        curDot = iter->getPosition();
//        curDot.move(0, value, 0);
//        iter->setPosition(curDot);
//    }
//    plateModel->setVertices(vertices);

//    for (size_t i = 0; i < modelsNum; i++)
//    {
//        vertices = models.at(i).getVertices();
//        for (std::vector<Vertex>::iterator iter = vertices.begin(); iter != vertices.end();
//             iter++)
//        {
//            curDot = iter->getPosition();
//            curDot.move(0, value, 0);
//            iter->setPosition(curDot);
//        }

//        models.at(i).setVertices(vertices);
//    }
}

void CellScene::moveLeft(double value)
{
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, -value,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1;

    transMatrix *= moveMat;
//    centerDot.move(-value, 0, 0);

//    Dot3D curDot;
//    std::vector<Vertex> vertices = plateModel->getVertices();
//    for (std::vector<Vertex>::iterator iter = vertices.begin(); iter != vertices.end();
//         iter++)
//    {
//        curDot = iter->getPosition();
//        curDot.move(-value, 0, 0);
//        iter->setPosition(curDot);
//    }
//    plateModel->setVertices(vertices);

//    for (size_t i = 0; i < modelsNum; i++)
//    {
//        vertices = models.at(i).getVertices();
//        for (std::vector<Vertex>::iterator iter = vertices.begin(); iter != vertices.end();
//             iter++)
//        {
//            curDot = iter->getPosition();
//            curDot.move(-value, 0, 0);
//            iter->setPosition(curDot);
//        }

//        models.at(i).setVertices(vertices);
//    }
}

void CellScene::moveRight(double value)
{
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, value,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1;

    transMatrix *= moveMat;
//    centerDot.move(value, 0, 0);

//    Dot3D curDot;
//    std::vector<Vertex> vertices = plateModel->getVertices();
//    //    qDebug() << "До";
//    //    for (int i = 0; i < (int)vertices.size(); i++)
//    //        qDebug() << vertices.at(i).getPosition();
//    for (std::vector<Vertex>::iterator iter = vertices.begin(); iter != vertices.end();
//         iter++)
//    {
//        curDot = iter->getPosition();
//        curDot.move(value, 0, 0);
//        iter->setPosition(curDot);
//    }
//    //    qDebug() << "После";
//    //    for (int i = 0; i < (int)vertices.size(); i++)
//    //        qDebug() << vertices.at(i).getPosition();
//    plateModel->setVertices(vertices);

//    for (size_t i = 0; i < modelsNum; i++)
//    {
//        vertices = models.at(i).getVertices();
//        for (std::vector<Vertex>::iterator iter = vertices.begin(); iter != vertices.end();
//             iter++)
//        {
//            curDot = iter->getPosition();
//            curDot.move(value, 0, 0);
//            iter->setPosition(curDot);
//        }

//        models.at(i).setVertices(vertices);
//    }
}

void CellScene::rotateX(double angle)
{
    Eigen::Matrix4f rotateMatrix;
    // clang-format off
    rotateMatrix << 1,           0,          0, 0,
                    0, cos(angle), -sin(angle), 0,
                    0, sin(angle),  cos(angle), 0,
                    0,           0,          0, 1;
    // clang-format on

    transMatrix *= rotateMatrix;
//    Dot3D curDot;
//    std::vector<Vertex> vertices = plateModel->getVertices();
//    for (std::vector<Vertex>::iterator iter = vertices.begin(); iter != vertices.end();
//         iter++)
//    {
//        curDot = iter->getPosition();
//        curDot.rotateX(angle, centerDot.getXCoordinate(), centerDot.getYCoordinate(), centerDot.getZCoordinate());
//        iter->setPosition(curDot);
//    }

//    plateModel->setVertices(vertices);

//    for (size_t i = 0; i < modelsNum; i++)
//    {
//        vertices = models.at(i).getVertices();
//        for (std::vector<Vertex>::iterator iter = vertices.begin(); iter != vertices.end();
//             iter++)
//        {
//            curDot = iter->getPosition();
//            curDot.rotateX(angle, centerDot.getXCoordinate(), centerDot.getYCoordinate(), centerDot.getZCoordinate());
//            iter->setPosition(curDot);
//        }

//        models.at(i).setVertices(vertices);
//    }
}

void CellScene::rotateY(double angle)
{
    Eigen::Matrix4f rotateMatrix;
    // clang-format off
    rotateMatrix << cos(angle),  0, sin(angle), 0,
                    0,           1,          0, 0,
                    -sin(angle), 0, cos(angle), 0,
                    0,           0,          0, 1;
    // clang-format on

    transMatrix *= rotateMatrix;
//    Dot3D curDot;
//    std::vector<Vertex> vertices = plateModel->getVertices();
//    for (std::vector<Vertex>::iterator iter = vertices.begin(); iter != vertices.end();
//         iter++)
//    {
//        curDot = iter->getPosition();
//        curDot.rotateY(angle, centerDot.getXCoordinate(), centerDot.getYCoordinate(), centerDot.getZCoordinate());
//        iter->setPosition(curDot);
//    }

//    plateModel->setVertices(vertices);

//    for (size_t i = 0; i < modelsNum; i++)
//    {
//        vertices = models.at(i).getVertices();
//        for (std::vector<Vertex>::iterator iter = vertices.begin(); iter != vertices.end();
//             iter++)
//        {
//            curDot = iter->getPosition();
//            curDot.rotateY(angle, centerDot.getXCoordinate(), centerDot.getYCoordinate(), centerDot.getZCoordinate());
//            iter->setPosition(curDot);
//        }

//        models.at(i).setVertices(vertices);
//    }
}

size_t CellScene::getModelsNum() { return modelsNum; }

PolModel &CellScene::getModel(size_t num) { return models.at(num); }

void CellScene::addModel(PolModel &model)
{
    modelsNum++;
    models.push_back(model);
}

size_t CellScene::getIllumNum() { return illumNum; }

Illuminant &CellScene::getIlluminant(size_t num) { return illuminants.at(num); }

PolModel &CellScene::getPlateModel() { return *plateModel; }

const Dot3D CellScene::getStartOfPlate() { return startOfPlate; }

void CellScene::setStartOfPlate(Dot3D dot_) { startOfPlate = dot_; }

const Dot3D CellScene::getEndOfPlate() { return endOfPlate; }

void CellScene::buildPlateModel(Dot3D startOfPlate_, Dot3D endOfPlate_)
{
    if (plateModel)
        return;
    setStartOfPlate(startOfPlate_);
    setEndOfPlate(endOfPlate_);

    std::vector<Vertex> vertices;
    std::vector<Facet> facets;

    size_t facetNum = 0;
    size_t vertexNum = 0;

    centerDot = Dot3D(startOfPlate_.getXCoordinate() + endOfPlate_.getXCoordinate() / 2, startOfPlate_.getYCoordinate() + endOfPlate_.getYCoordinate() / 2, PLATE_Z);

    for (size_t y = startOfPlate_.getYCoordinate(); y < endOfPlate_.getYCoordinate();
         y += SCALE_FACTOR)
    {
        for (size_t x = startOfPlate_.getXCoordinate(); x < endOfPlate_.getXCoordinate();
             x += SCALE_FACTOR, facetNum += 4, vertexNum += 5)
        {
            Dot3D start(x, y, PLATE_Z);
            vertices.push_back(
            Vertex(start)); // std::vector<size_t>{facetNum, facetNum + 1}));
            Dot3D middleDot(x + SCALE_FACTOR / 2, y + SCALE_FACTOR / 2, PLATE_Z);
            vertices.push_back(
            Vertex(middleDot)); // std::vector<size_t>{facetNum + 0, facetNum + 1,
                                // facetNum + 2, facetNum + 3}));
            Dot3D end(x + SCALE_FACTOR, y + SCALE_FACTOR, PLATE_Z);
            vertices.push_back(
            Vertex(end)); // std::vector<size_t>{facetNum + 2, facetNum + 3}));
            Dot3D leftBot(x, y + SCALE_FACTOR, PLATE_Z);
            vertices.push_back(
            Vertex(leftBot)); // std::vector<size_t>{facetNum + 0, facetNum + 3}));
            Dot3D rightTop(x + SCALE_FACTOR, y, PLATE_Z);
            vertices.push_back(
            Vertex(rightTop)); // std::vector<size_t>{facetNum + 1, facetNum + 2}));

            facets.push_back(
            std::vector<size_t>{vertexNum, vertexNum + 1, vertexNum + 3});
            facets.push_back(
            std::vector<size_t>{vertexNum, vertexNum + 1, vertexNum + 4});
            facets.push_back(
            std::vector<size_t>{vertexNum + 1, vertexNum + 2, vertexNum + 4});
            facets.push_back(
            std::vector<size_t>{vertexNum + 1, vertexNum + 2, vertexNum + 3});
        }
    }

    //    Dot3D exDot(startOfPlate_.getXCoordinate() + (endOfPlate_.getXCoordinate() -
    //                                                  startOfPlate_.getXCoordinate()) /
    //                                                  2,
    //    endOfPlate_.getYCoordinate() - (endOfPlate_.getYCoordinate() -
    //                                                startOfPlate_.getYCoordinate()) / 2,
    //    startOfPlate_.getZCoordinate());

    //    std::vector<Vertex> vertices;
    //    vertices.push_back(Vertex(startOfPlate_, std::vector<size_t>{0, 1}));
    //    vertices.push_back(Vertex(exDot, std::vector<size_t>{0, 1, 2, 3}));
    //    vertices.push_back(Vertex(endOfPlate_, std::vector<size_t>{2, 3}));

    //    exDot.setXCoordinate(startOfPlate_.getXCoordinate());
    //    exDot.setYCoordinate(endOfPlate_.getYCoordinate());
    //    vertices.push_back(Vertex(exDot, std::vector<size_t>{0, 3}));

    //    exDot.setXCoordinate(endOfPlate_.getXCoordinate());
    //    exDot.setYCoordinate(startOfPlate_.getYCoordinate());
    //    vertices.push_back(Vertex(exDot, std::vector<size_t>{1, 2}));

    //    std::vector<Facet> facets;
    //    facets.push_back(std::vector<size_t>{0, 1, 3});
    //    facets.push_back(std::vector<size_t>{0, 1, 4});
    //    facets.push_back(std::vector<size_t>{1, 2, 4});
    //    facets.push_back(std::vector<size_t>{1, 2, 3});

    //    Dot3D newDiagDot(startOfPlate_.getXCoordinate(), endOfPlate_.getYCoordinate(),
    //    startOfPlate_.getZCoordinate());

    //    std::vector<Vertex> vertices;
    //    vertices.push_back(Vertex(startOfPlate_, std::vector<size_t>{0}));
    //    vertices.push_back(Vertex(newDiagDot, std::vector<size_t>{0, 1}));
    //    vertices.push_back(Vertex(endOfPlate_, std::vector<size_t>{1}));

    //    newDiagDot.setXCoordinate(endOfPlate_.getXCoordinate());
    //    newDiagDot.setYCoordinate(startOfPlate_.getYCoordinate());
    //    newDiagDot.setZCoordinate(startOfPlate_.getZCoordinate());
    //    vertices.push_back(Vertex(newDiagDot, std::vector<size_t>{0, 1}));

    //    std::vector<Facet> facets;
    //    facets.push_back(std::vector<size_t>{0, 1, 2});
    //    facets.push_back(std::vector<size_t>{0, 2, 3});

    if (plateModel)
        delete plateModel;
    plateModel = new PolModel(vertices, facets);

    //    // Debug
    //    for (size_t i = 0; i < plateModel->getVertices().size(); i++)
    //        qDebug() << plateModel->getVertices().at(i).getPosition();
}

void CellScene::setEndOfPlate(Dot3D dot_) { endOfPlate = dot_; }

void CellScene::changeSize(size_t newWidth, size_t newheight)
{
    if (newWidth >= width)
        width = newWidth;
    //    else Вот тут потребуется анализ ситуации...
//    qDebug("%zu is new width\n", width);

    if (newheight >= height)
        height = newheight;
    //    else Тоже самое

//    qDebug("%zu is new height\n", height);
}

#include "clipping.h"

#include "line.h"
#include "point.h"

#include <gtest/gtest.h>
#include <memory>
#include "bezier.h"

class ClipTest
  : public testing::Test
{
protected:
  void SetUp() override
  {
    geometries::Point minVpPoint(0, 0);
    geometries::Point maxVpPoint(10, 10);

    clip.reset(new clipping::Clip(minVpPoint, maxVpPoint));
  }

protected:
  std::unique_ptr<clipping::Clip> clip;
};

TEST_F(ClipTest, CohenSutherlandLineClippingLeft)
{
  geometries::Line line(new geometries::Point(-2, 5), new geometries::Point(5, 5), "Line");
  
  std::vector<geometries::Point> expected = {
    geometries::Point(0, 5), 
    geometries::Point(5, 5) 
  };

  auto lineClipped = clip->cSutherlandLine(line.getP1(), line.getP2());

  for (std::size_t i = 0; i < lineClipped.size(); ++i)
  {
    ASSERT_EQ(expected.at(i), lineClipped.at(i));
  }
}

TEST_F(ClipTest, CohenSutherlandLineClippingTop)
{
  geometries::Line line(new geometries::Point(5, -2), new geometries::Point(5, 5), "Line");

  std::vector<geometries::Point> expected = {
    geometries::Point(5, 0),
    geometries::Point(5, 5)
  };

  auto lineClipped = clip->cSutherlandLine(line.getP1(), line.getP2());

  for (std::size_t i = 0; i < lineClipped.size(); ++i)
  {
    ASSERT_EQ(expected.at(i), lineClipped.at(i));
  }
}

TEST_F(ClipTest, CohenSutherlandLineClippingRight)
{
  geometries::Line line(new geometries::Point(5, 5), new geometries::Point(12, 5), "Line");

  std::vector<geometries::Point> expected = {
    geometries::Point(5, 5),
    geometries::Point(10, 5)
  };

  auto lineClipped = clip->cSutherlandLine(line.getP1(), line.getP2());

  for (std::size_t i = 0; i < lineClipped.size(); ++i)
  {
    ASSERT_EQ(expected.at(i), lineClipped.at(i));
  }
}

TEST_F(ClipTest, CohenSutherlandLineClippingBottom)
{
  geometries::Line line(new geometries::Point(5, 5), new geometries::Point(5, 12), "Line");

  std::vector<geometries::Point> expected = {
    geometries::Point(5, 5),
    geometries::Point(5, 10)
  };

  auto lineClipped = clip->cSutherlandLine(line.getP1(), line.getP2());

  for (std::size_t i = 0; i < lineClipped.size(); ++i)
  {
    ASSERT_EQ(expected.at(i), lineClipped.at(i));
  }
}

TEST_F(ClipTest, CohenSutherlandLineClippingInside)
{
  geometries::Line line(new geometries::Point(2, 5), new geometries::Point(7, 5), "Line");

  std::vector<geometries::Point> expected = {
    geometries::Point(2, 5),
    geometries::Point(7, 5)
  };

  auto lineClipped = clip->cSutherlandLine(line.getP1(), line.getP2());

  for (std::size_t i = 0; i < lineClipped.size(); ++i)
  {
    ASSERT_EQ(expected.at(i), lineClipped.at(i));
  }
}

TEST_F(ClipTest, CohenSutherlandLineClippingLeft2Top)
{
  geometries::Line line(new geometries::Point(-2, 7), new geometries::Point(7, -2), "Line");

  std::vector<geometries::Point> expected = {
    geometries::Point(0, 5),
    geometries::Point(5, 0)
  };

  auto lineClipped = clip->cSutherlandLine(line.getP1(), line.getP2());

  for (std::size_t i = 0; i < lineClipped.size(); ++i)
  {
    ASSERT_EQ(expected.at(i), lineClipped.at(i));
  }
}

TEST_F(ClipTest, LiangBarskyLineClippingLeft)
{
  geometries::Line line(new geometries::Point(-2, 5), new geometries::Point(5, 5), "Line");

  std::vector<geometries::Point> expected = {
    geometries::Point(0, 5),
    geometries::Point(5, 5)
  };

  auto lineClipped = clip->lBarskyLine(line.getP1(), line.getP2());

  for (std::size_t i = 0; i < lineClipped.size(); ++i)
  {
    ASSERT_EQ(expected.at(i), lineClipped.at(i));
  }
}

TEST_F(ClipTest, LiangBarskyLineClippingTop)
{
  geometries::Line line(new geometries::Point(5, -2), new geometries::Point(5, 5), "Line");

  std::vector<geometries::Point> expected = {
    geometries::Point(5, 0),
    geometries::Point(5, 5)
  };

  auto lineClipped = clip->lBarskyLine(line.getP1(), line.getP2());

  for (std::size_t i = 0; i < lineClipped.size(); ++i)
  {
    ASSERT_EQ(expected.at(i), lineClipped.at(i));
  }
}

TEST_F(ClipTest, LiangBarskyLineClippingRight)
{
  geometries::Line line(new geometries::Point(5, 5), new geometries::Point(12, 5), "Line");

  std::vector<geometries::Point> expected = {
    geometries::Point(5, 5),
    geometries::Point(10, 5)
  };

  auto lineClipped = clip->lBarskyLine(line.getP1(), line.getP2());

  for (std::size_t i = 0; i < lineClipped.size(); ++i)
  {
    ASSERT_EQ(expected.at(i), lineClipped.at(i));
  }
}

TEST_F(ClipTest, LiangBarskyLineClippingBottom)
{
  geometries::Line line(new geometries::Point(5, 5), new geometries::Point(5, 12), "Line");

  std::vector<geometries::Point> expected = {
    geometries::Point(5, 5),
    geometries::Point(5, 10)
  };

  auto lineClipped = clip->lBarskyLine(line.getP1(), line.getP2());

  for (std::size_t i = 0; i < lineClipped.size(); ++i)
  {
    ASSERT_EQ(expected.at(i), lineClipped.at(i));
  }
}

TEST_F(ClipTest, LiangBarskyLineClippingInside)
{
  geometries::Line line(new geometries::Point(2, 5), new geometries::Point(7, 5), "Line");

  std::vector<geometries::Point> expected = {
    geometries::Point(2, 5),
    geometries::Point(7, 5)
  };

  auto lineClipped = clip->lBarskyLine(line.getP1(), line.getP2());

  for (std::size_t i = 0; i < lineClipped.size(); ++i)
  {
    ASSERT_EQ(expected.at(i), lineClipped.at(i));
  }
}

TEST_F(ClipTest, LiangBarskyLineClippingLeft2Top)
{
  geometries::Line line(new geometries::Point(-2, 7), new geometries::Point(7, -2), "Line");

  std::vector<geometries::Point> expected = {
    geometries::Point(0, 5),
    geometries::Point(5, 0)
  };

  auto lineClipped = clip->lBarskyLine(line.getP1(), line.getP2());

  for (std::size_t i = 0; i < lineClipped.size(); ++i)
  {
    ASSERT_EQ(expected.at(i), lineClipped.at(i));
  }
}

#include "stdafx.h"
#include <Windows.h>
#include "Vector3.h"

// IMPORTANT NOTE: OutputDebugStringA() can interact strangely with changes. If retesting and changing numbers Move to Game.cpp and add a space in OutputDebugStringA("Vector3Test Results:\n"); then it will print.
class Vector3Test
{

public:
    static void RunTests()
    {
        Vector3 v = Vector3(25.0f, 25.0f, 25.0f);
        Vector3 v2 = Vector3(1.0f, 1.0f, 1.0f);

        Vector3 vUp = Vector3::Up;

        float n = 2.0f;

        TestAdd(v, v2);
        TestCompoundAdd(v, v2);
        TestSubtract(v, v2);
        TestCompoundSubtract(v, v2);
        TestMultiply(v, n);
        TestCompoundMultiply(v, n);
        TestDivide(v, n);
        TestCompoundDivide(v, n);
        TestMagnitude(v);
        TestNormalize(v);
        TestDot(v, v2);
        TestCross(v, v2);
        TestEquals(v, v2);
        TestNotEquals(v, v2);
        TestDistance(v, v2);

    }

private:

    static void TestAdd(Vector3& v, Vector3& v2)
    {
        Vector3 result = v + v2;

        std::string resultString = ("TestAdd(): " + result.ToString() + "\n");
        OutputDebugStringA(resultString.c_str());

    }

    static void TestCompoundAdd(Vector3& v, Vector3& v2)
    {
        Vector3 result = v + v2;
        result += result;

        std::string resultString = ("TestCompoundAdd(): " + result.ToString() + "\n");
        OutputDebugStringA(resultString.c_str());

    }

    static void TestSubtract(Vector3& v, Vector3& v2)
    {
        Vector3 result = v - v2;

        std::string resultString = ("TestSubtract(): " + result.ToString() + "\n");
        OutputDebugStringA(resultString.c_str());

    }

    static void TestCompoundSubtract(Vector3& v, Vector3& v2)
    {
        Vector3 result = v - v2;
        result -= result;

        std::string resultString = ("TestCompoundSubtract(): " + result.ToString() + "\n");
        OutputDebugStringA(resultString.c_str());

    }

    static void TestMultiply(Vector3& v, float& n)
    {
        Vector3 result = v * n;

        std::string resultString = ("TestMultiply(): " + result.ToString() + "\n");
        OutputDebugStringA(resultString.c_str());

    }

    static void TestCompoundMultiply(Vector3& v, float& n)
    {
        Vector3 result = v * n;
        result *= n;

        std::string resultString = ("TestCompoundMultiply(): " + result.ToString() + "\n");
        OutputDebugStringA(resultString.c_str());

    }

    static void TestDivide(Vector3& v, float& n)
    {
        Vector3 result = v / n;

        std::string resultString = ("TestDivide(): " + result.ToString() + "\n");
        OutputDebugStringA(resultString.c_str());

    }

    static void TestCompoundDivide(Vector3& v, float& n)
    {
        Vector3 result = v / n;
        result /= n;

        std::string resultString = ("TestCompoundDivide(): " + result.ToString() + "\n");
        OutputDebugStringA(resultString.c_str());

    }

    static void TestMagnitude(Vector3& v)
    {
        float magnitude = v.Magnitude();

        std::string resultString = ("TestMagnitude(): " + std::to_string(magnitude) + "\n");
        OutputDebugStringA(resultString.c_str());

    }

    static void TestNormalize(Vector3& v)
    {
        float magnitude = v.Magnitude();
        Vector3 result = v.Normalize();

        std::string resultString = ("TestNormalize(): " + result.ToString() + "\n");
        OutputDebugStringA(resultString.c_str());

    }

    static void TestDot(Vector3& v, Vector3& v2)
    {
        float dot = v.Dot(v2);

        std::string resultString = ("TestDot(): " + std::to_string(dot) + "\n");
        OutputDebugStringA(resultString.c_str());

        Vector3 normalizedV = v.Normalize();
        Vector3 normalizedV2 = v2.Normalize();

        float dot2 = normalizedV.Dot(normalizedV2);

        std::string resultString2 = ("TestDot(): [normalized]: " + std::to_string(dot2) + "\n");
        OutputDebugStringA(resultString2.c_str());

    }

    static void TestCross(Vector3& v, Vector3& v2)
    {
        Vector3 result = v.Cross(v2);

        std::string resultString = ("TestCross(): " + result.ToString() + "\n");
        OutputDebugStringA(resultString.c_str());

    }

    static void TestEquals(Vector3& v, Vector3& v2)
    {
        if (v == v2)
        {
            std::string resultString = ("TestEquals: MATCH \n");
            OutputDebugStringA(resultString.c_str());
        }
        else
        {
            std::string resultString = ("TestEquals: NO MATCH \n");
            OutputDebugStringA(resultString.c_str());
        }

    }
    
    static void TestNotEquals(Vector3& v, Vector3& v2)
    {
        if (v != v2)
        {
            std::string resultString = ("TestNotEquals: NO MATCH \n");
            OutputDebugStringA(resultString.c_str());
        }
        else
        {
            std::string resultString = ("TestNotEquals: MATCH \n");
            OutputDebugStringA(resultString.c_str());
        }
    }

    static void TestDistance(Vector3& v, Vector3& v2)
    {
        float result = Vector3::Distance(v, v2);
        std::string resultString = ("TestDistance: " + std::to_string(result) + "\n");
        OutputDebugStringA(resultString.c_str());
    }
};
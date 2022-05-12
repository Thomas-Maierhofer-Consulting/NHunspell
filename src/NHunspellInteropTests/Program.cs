using System;
using NHunspell;

namespace NHunspellInteropTests
{
    class Program
    {
        static void Main(string[] args)
        {
            NHunspell.Hunspell.NativeDllPath = "D:/Projects/TMC/NHunspell/NHunspell/HunspellNative/build/Debug";
            NHunspell.Hunspell.NativeDllName = "HunspellNative.dll";

            Console.WriteLine("Running Hunspell");

            using (Hunspell hunspell = new Hunspell("TestData/en_us.aff", "TestData/en_us.dic"))
            {
                var spellResult = hunspell.Spell("houses");
            }

            Console.WriteLine("Running Hyphen");
            using (Hyphen hyphen = new Hyphen("TestData/hyph_en_US.dic"))
            {
                var hyphenateResult = hyphen.Hyphenate("insurrection");
            }

        }
    }
}

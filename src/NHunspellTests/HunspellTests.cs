using System;
using FluentAssertions;
using NHunspell;
using Xunit;

namespace NHunspellTests
{
    public class HunspellTests
    {
        [Fact]
        public void CreationAndDestructionTest()
        {
            Hunspell hunspell = new Hunspell("TestData/en_us.aff", "TestData/en_us.dic");
            hunspell.IsDisposed.Should().BeFalse();

            // Multiple dispose must be allowed
            hunspell.Dispose();
            hunspell.IsDisposed.Should().BeTrue();
            hunspell.Dispose();
            hunspell.IsDisposed.Should().BeTrue();
        }

        [Fact]
        public void GenerationTest()
        {
            using (Hunspell hunspell = new Hunspell("TestData/en_us.aff", "TestData/en_us.dic"))
            {
                var generated = hunspell.Generate("boy", "girls");
                foreach (var gen in generated)
                {

                }
            }
        }

        [Fact]
        public void SpellComplexWordsTest()
        {
            using (Hunspell hunspell = new Hunspell("TestData/en_us.aff", "TestData/en_us.dic"))
            {
                hunspell.Spell("houses").Should().BeTrue(); // plural
                hunspell.Spell("stockbroker").Should().BeTrue(); // compound
            }
        }
    }
}

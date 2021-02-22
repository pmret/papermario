.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013B0EC
/* D17EC 8013B0EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D17F0 8013B0F0 AFB00010 */  sw        $s0, 0x10($sp)
/* D17F4 8013B0F4 0080802D */  daddu     $s0, $a0, $zero
/* D17F8 8013B0F8 AFBF0014 */  sw        $ra, 0x14($sp)
/* D17FC 8013B0FC 92030001 */  lbu       $v1, 1($s0)
/* D1800 8013B100 2C620005 */  sltiu     $v0, $v1, 5
/* D1804 8013B104 10400026 */  beqz      $v0, .L8013B1A0
/* D1808 8013B108 00031080 */   sll      $v0, $v1, 2
/* D180C 8013B10C 3C018015 */  lui       $at, %hi(jtbl_80151038)
/* D1810 8013B110 00220821 */  addu      $at, $at, $v0
/* D1814 8013B114 8C221038 */  lw        $v0, %lo(jtbl_80151038)($at)
/* D1818 8013B118 00400008 */  jr        $v0
/* D181C 8013B11C 00000000 */   nop
glabel L8013B120_D1820
/* D1820 8013B120 8E020034 */  lw        $v0, 0x34($s0)
/* D1824 8013B124 14400004 */  bnez      $v0, .L8013B138
/* D1828 8013B128 24020001 */   addiu    $v0, $zero, 1
/* D182C 8013B12C A2020003 */  sb        $v0, 3($s0)
/* D1830 8013B130 0804EC4F */  j         .L8013B13C
/* D1834 8013B134 24020010 */   addiu    $v0, $zero, 0x10
.L8013B138:
/* D1838 8013B138 A2020003 */  sb        $v0, 3($s0)
.L8013B13C:
/* D183C 8013B13C A2020004 */  sb        $v0, 4($s0)
glabel L8013B140_D1840
/* D1840 8013B140 0C04F012 */  jal       func_8013C048
/* D1844 8013B144 0200202D */   daddu    $a0, $s0, $zero
/* D1848 8013B148 0804EC5A */  j         .L8013B168
/* D184C 8013B14C 00000000 */   nop
glabel L8013B150_D1850
/* D1850 8013B150 0C04F0FC */  jal       func_8013C3F0
/* D1854 8013B154 0200202D */   daddu    $a0, $s0, $zero
/* D1858 8013B158 0804EC5A */  j         .L8013B168
/* D185C 8013B15C 00000000 */   nop
glabel L8013B160_D1860
/* D1860 8013B160 0C04EF22 */  jal       func_8013BC88
/* D1864 8013B164 0200202D */   daddu    $a0, $s0, $zero
.L8013B168:
/* D1868 8013B168 82030005 */  lb        $v1, 5($s0)
/* D186C 8013B16C 24020004 */  addiu     $v0, $zero, 4
/* D1870 8013B170 14620003 */  bne       $v1, $v0, .L8013B180
/* D1874 8013B174 00000000 */   nop
/* D1878 8013B178 0C04FB9A */  jal       func_8013EE68
/* D187C 8013B17C 0200202D */   daddu    $a0, $s0, $zero
.L8013B180:
/* D1880 8013B180 82030006 */  lb        $v1, 6($s0)
/* D1884 8013B184 2862000D */  slti      $v0, $v1, 0xd
/* D1888 8013B188 10400005 */  beqz      $v0, .L8013B1A0
/* D188C 8013B18C 2862000B */   slti     $v0, $v1, 0xb
/* D1890 8013B190 14400003 */  bnez      $v0, .L8013B1A0
/* D1894 8013B194 00000000 */   nop
/* D1898 8013B198 0C04FC7E */  jal       func_8013F1F8
/* D189C 8013B19C 0200202D */   daddu    $a0, $s0, $zero
.L8013B1A0:
/* D18A0 8013B1A0 8FBF0014 */  lw        $ra, 0x14($sp)
/* D18A4 8013B1A4 8FB00010 */  lw        $s0, 0x10($sp)
/* D18A8 8013B1A8 03E00008 */  jr        $ra
/* D18AC 8013B1AC 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E000E174
/* 32C284 E000E174 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 32C288 E000E178 AFBF0010 */  sw        $ra, 0x10($sp)
/* 32C28C E000E17C 8C86000C */  lw        $a2, 0xc($a0)
/* 32C290 E000E180 8CC2006C */  lw        $v0, 0x6c($a2)
/* 32C294 E000E184 8CC30070 */  lw        $v1, 0x70($a2)
/* 32C298 E000E188 00021080 */  sll       $v0, $v0, 2
/* 32C29C E000E18C 3C01E001 */  lui       $at, 0xe001
/* 32C2A0 E000E190 00220821 */  addu      $at, $at, $v0
/* 32C2A4 E000E194 8C22E684 */  lw        $v0, -0x197c($at)
/* 32C2A8 E000E198 00431021 */  addu      $v0, $v0, $v1
/* 32C2AC E000E19C 80420000 */  lb        $v0, ($v0)
/* 32C2B0 E000E1A0 24630001 */  addiu     $v1, $v1, 1
/* 32C2B4 E000E1A4 ACC30070 */  sw        $v1, 0x70($a2)
/* 32C2B8 E000E1A8 04410005 */  bgez      $v0, .LE000E1C0
/* 32C2BC E000E1AC ACC20074 */   sw       $v0, 0x74($a2)
/* 32C2C0 E000E1B0 0C080128 */  jal       func_E02004A0
/* 32C2C4 E000E1B4 00000000 */   nop      
/* 32C2C8 E000E1B8 0800388E */  j         .LE000E238
/* 32C2CC E000E1BC 00000000 */   nop      
.LE000E1C0:
/* 32C2D0 E000E1C0 8C820008 */  lw        $v0, 8($a0)
/* 32C2D4 E000E1C4 1840001C */  blez      $v0, .LE000E238
/* 32C2D8 E000E1C8 0000282D */   daddu    $a1, $zero, $zero
/* 32C2DC E000E1CC 24C3000C */  addiu     $v1, $a2, 0xc
.LE000E1D0:
/* 32C2E0 E000E1D0 C462004C */  lwc1      $f2, 0x4c($v1)
/* 32C2E4 E000E1D4 C4600058 */  lwc1      $f0, 0x58($v1)
/* 32C2E8 E000E1D8 46001082 */  mul.s     $f2, $f2, $f0
/* 32C2EC E000E1DC 00000000 */  nop       
/* 32C2F0 E000E1E0 C468004C */  lwc1      $f8, 0x4c($v1)
/* 32C2F4 E000E1E4 C460005C */  lwc1      $f0, 0x5c($v1)
/* 32C2F8 E000E1E8 46004202 */  mul.s     $f8, $f8, $f0
/* 32C2FC E000E1EC 00000000 */  nop       
/* 32C300 E000E1F0 C466FFFC */  lwc1      $f6, -4($v1)
/* 32C304 E000E1F4 C4600054 */  lwc1      $f0, 0x54($v1)
/* 32C308 E000E1F8 46023180 */  add.s     $f6, $f6, $f2
/* 32C30C E000E1FC C4620050 */  lwc1      $f2, 0x50($v1)
/* 32C310 E000E200 46001080 */  add.s     $f2, $f2, $f0
/* 32C314 E000E204 C4640004 */  lwc1      $f4, 4($v1)
/* 32C318 E000E208 46082100 */  add.s     $f4, $f4, $f8
/* 32C31C E000E20C C4600000 */  lwc1      $f0, ($v1)
/* 32C320 E000E210 24A50001 */  addiu     $a1, $a1, 1
/* 32C324 E000E214 E466FFFC */  swc1      $f6, -4($v1)
/* 32C328 E000E218 46020000 */  add.s     $f0, $f0, $f2
/* 32C32C E000E21C E4620050 */  swc1      $f2, 0x50($v1)
/* 32C330 E000E220 E4640004 */  swc1      $f4, 4($v1)
/* 32C334 E000E224 E4600000 */  swc1      $f0, ($v1)
/* 32C338 E000E228 8C820008 */  lw        $v0, 8($a0)
/* 32C33C E000E22C 00A2102A */  slt       $v0, $a1, $v0
/* 32C340 E000E230 1440FFE7 */  bnez      $v0, .LE000E1D0
/* 32C344 E000E234 24630078 */   addiu    $v1, $v1, 0x78
.LE000E238:
/* 32C348 E000E238 8FBF0010 */  lw        $ra, 0x10($sp)
/* 32C34C E000E23C 03E00008 */  jr        $ra
/* 32C350 E000E240 27BD0018 */   addiu    $sp, $sp, 0x18

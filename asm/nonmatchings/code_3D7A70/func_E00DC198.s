.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00DC198
/* 3D7C08 E00DC198 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3D7C0C E00DC19C AFBF0010 */  sw        $ra, 0x10($sp)
/* 3D7C10 E00DC1A0 8C850000 */  lw        $a1, ($a0)
/* 3D7C14 E00DC1A4 8C83000C */  lw        $v1, 0xc($a0)
/* 3D7C18 E00DC1A8 30A20010 */  andi      $v0, $a1, 0x10
/* 3D7C1C E00DC1AC 10400005 */  beqz      $v0, .LE00DC1C4
/* 3D7C20 E00DC1B0 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3D7C24 E00DC1B4 00A21024 */  and       $v0, $a1, $v0
/* 3D7C28 E00DC1B8 AC820000 */  sw        $v0, ($a0)
/* 3D7C2C E00DC1BC 24020010 */  addiu     $v0, $zero, 0x10
/* 3D7C30 E00DC1C0 AC620010 */  sw        $v0, 0x10($v1)
.LE00DC1C4:
/* 3D7C34 E00DC1C4 8C650010 */  lw        $a1, 0x10($v1)
/* 3D7C38 E00DC1C8 28A203E8 */  slti      $v0, $a1, 0x3e8
/* 3D7C3C E00DC1CC 10400002 */  beqz      $v0, .LE00DC1D8
/* 3D7C40 E00DC1D0 24A2FFFF */   addiu    $v0, $a1, -1
/* 3D7C44 E00DC1D4 AC620010 */  sw        $v0, 0x10($v1)
.LE00DC1D8:
/* 3D7C48 E00DC1D8 8C620014 */  lw        $v0, 0x14($v1)
/* 3D7C4C E00DC1DC 8C650010 */  lw        $a1, 0x10($v1)
/* 3D7C50 E00DC1E0 24460001 */  addiu     $a2, $v0, 1
/* 3D7C54 E00DC1E4 04A10005 */  bgez      $a1, .LE00DC1FC
/* 3D7C58 E00DC1E8 AC660014 */   sw       $a2, 0x14($v1)
/* 3D7C5C E00DC1EC 0C080128 */  jal       func_E02004A0
/* 3D7C60 E00DC1F0 00000000 */   nop      
/* 3D7C64 E00DC1F4 080370AD */  j         .LE00DC2B4
/* 3D7C68 E00DC1F8 00000000 */   nop      
.LE00DC1FC:
/* 3D7C6C E00DC1FC 28A20010 */  slti      $v0, $a1, 0x10
/* 3D7C70 E00DC200 10400002 */  beqz      $v0, .LE00DC20C
/* 3D7C74 E00DC204 00051100 */   sll      $v0, $a1, 4
/* 3D7C78 E00DC208 AC620024 */  sw        $v0, 0x24($v1)
.LE00DC20C:
/* 3D7C7C E00DC20C 28C20010 */  slti      $v0, $a2, 0x10
/* 3D7C80 E00DC210 10400003 */  beqz      $v0, .LE00DC220
/* 3D7C84 E00DC214 00061100 */   sll      $v0, $a2, 4
/* 3D7C88 E00DC218 2442000F */  addiu     $v0, $v0, 0xf
/* 3D7C8C E00DC21C AC620024 */  sw        $v0, 0x24($v1)
.LE00DC220:
/* 3D7C90 E00DC220 C4620038 */  lwc1      $f2, 0x38($v1)
/* 3D7C94 E00DC224 C460003C */  lwc1      $f0, 0x3c($v1)
/* 3D7C98 E00DC228 46001000 */  add.s     $f0, $f2, $f0
/* 3D7C9C E00DC22C 3C014380 */  lui       $at, 0x4380
/* 3D7CA0 E00DC230 44812000 */  mtc1      $at, $f4
/* 3D7CA4 E00DC234 00000000 */  nop       
/* 3D7CA8 E00DC238 4600203E */  c.le.s    $f4, $f0
/* 3D7CAC E00DC23C 00000000 */  nop       
/* 3D7CB0 E00DC240 45000003 */  bc1f      .LE00DC250
/* 3D7CB4 E00DC244 E4600038 */   swc1     $f0, 0x38($v1)
/* 3D7CB8 E00DC248 46040001 */  sub.s     $f0, $f0, $f4
/* 3D7CBC E00DC24C E4600038 */  swc1      $f0, 0x38($v1)
.LE00DC250:
/* 3D7CC0 E00DC250 C4600038 */  lwc1      $f0, 0x38($v1)
/* 3D7CC4 E00DC254 44803000 */  mtc1      $zero, $f6
/* 3D7CC8 E00DC258 00000000 */  nop       
/* 3D7CCC E00DC25C 4606003C */  c.lt.s    $f0, $f6
/* 3D7CD0 E00DC260 00000000 */  nop       
/* 3D7CD4 E00DC264 45000003 */  bc1f      .LE00DC274
/* 3D7CD8 E00DC268 00000000 */   nop      
/* 3D7CDC E00DC26C 46040000 */  add.s     $f0, $f0, $f4
/* 3D7CE0 E00DC270 E4600038 */  swc1      $f0, 0x38($v1)
.LE00DC274:
/* 3D7CE4 E00DC274 C4620040 */  lwc1      $f2, 0x40($v1)
/* 3D7CE8 E00DC278 C4600044 */  lwc1      $f0, 0x44($v1)
/* 3D7CEC E00DC27C 46001000 */  add.s     $f0, $f2, $f0
/* 3D7CF0 E00DC280 4600203E */  c.le.s    $f4, $f0
/* 3D7CF4 E00DC284 00000000 */  nop       
/* 3D7CF8 E00DC288 45000003 */  bc1f      .LE00DC298
/* 3D7CFC E00DC28C E4600040 */   swc1     $f0, 0x40($v1)
/* 3D7D00 E00DC290 46040001 */  sub.s     $f0, $f0, $f4
/* 3D7D04 E00DC294 E4600040 */  swc1      $f0, 0x40($v1)
.LE00DC298:
/* 3D7D08 E00DC298 C4600040 */  lwc1      $f0, 0x40($v1)
/* 3D7D0C E00DC29C 4606003C */  c.lt.s    $f0, $f6
/* 3D7D10 E00DC2A0 00000000 */  nop       
/* 3D7D14 E00DC2A4 45000003 */  bc1f      .LE00DC2B4
/* 3D7D18 E00DC2A8 00000000 */   nop      
/* 3D7D1C E00DC2AC 46040000 */  add.s     $f0, $f0, $f4
/* 3D7D20 E00DC2B0 E4600040 */  swc1      $f0, 0x40($v1)
.LE00DC2B4:
/* 3D7D24 E00DC2B4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3D7D28 E00DC2B8 03E00008 */  jr        $ra
/* 3D7D2C E00DC2BC 27BD0018 */   addiu    $sp, $sp, 0x18

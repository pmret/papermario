.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00BC238
/* 3BA268 E00BC238 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3BA26C E00BC23C AFBF0010 */  sw        $ra, 0x10($sp)
/* 3BA270 E00BC240 8C830000 */  lw        $v1, ($a0)
/* 3BA274 E00BC244 8C86000C */  lw        $a2, 0xc($a0)
/* 3BA278 E00BC248 30620010 */  andi      $v0, $v1, 0x10
/* 3BA27C E00BC24C 8CC70000 */  lw        $a3, ($a2)
/* 3BA280 E00BC250 10400005 */  beqz      $v0, .LE00BC268
/* 3BA284 E00BC254 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3BA288 E00BC258 00621024 */  and       $v0, $v1, $v0
/* 3BA28C E00BC25C AC820000 */  sw        $v0, ($a0)
/* 3BA290 E00BC260 24020010 */  addiu     $v0, $zero, 0x10
/* 3BA294 E00BC264 ACC20028 */  sw        $v0, 0x28($a2)
.LE00BC268:
/* 3BA298 E00BC268 8CC30028 */  lw        $v1, 0x28($a2)
/* 3BA29C E00BC26C 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3BA2A0 E00BC270 10400002 */  beqz      $v0, .LE00BC27C
/* 3BA2A4 E00BC274 2462FFFF */   addiu    $v0, $v1, -1
/* 3BA2A8 E00BC278 ACC20028 */  sw        $v0, 0x28($a2)
.LE00BC27C:
/* 3BA2AC E00BC27C 8CC2002C */  lw        $v0, 0x2c($a2)
/* 3BA2B0 E00BC280 8CC30028 */  lw        $v1, 0x28($a2)
/* 3BA2B4 E00BC284 24450001 */  addiu     $a1, $v0, 1
/* 3BA2B8 E00BC288 04610005 */  bgez      $v1, .LE00BC2A0
/* 3BA2BC E00BC28C ACC5002C */   sw       $a1, 0x2c($a2)
/* 3BA2C0 E00BC290 0C080128 */  jal       func_E02004A0
/* 3BA2C4 E00BC294 00000000 */   nop      
/* 3BA2C8 E00BC298 0802F0B7 */  j         .LE00BC2DC
/* 3BA2CC E00BC29C 00000000 */   nop      
.LE00BC2A0:
/* 3BA2D0 E00BC2A0 24020002 */  addiu     $v0, $zero, 2
/* 3BA2D4 E00BC2A4 14E20002 */  bne       $a3, $v0, .LE00BC2B0
/* 3BA2D8 E00BC2A8 28A2000B */   slti     $v0, $a1, 0xb
/* 3BA2DC E00BC2AC 28A20028 */  slti      $v0, $a1, 0x28
.LE00BC2B0:
/* 3BA2E0 E00BC2B0 1440000A */  bnez      $v0, .LE00BC2DC
/* 3BA2E4 E00BC2B4 00000000 */   nop      
/* 3BA2E8 E00BC2B8 3C013FE0 */  lui       $at, 0x3fe0
/* 3BA2EC E00BC2BC 44811800 */  mtc1      $at, $f3
/* 3BA2F0 E00BC2C0 44801000 */  mtc1      $zero, $f2
/* 3BA2F4 E00BC2C4 C4C0003C */  lwc1      $f0, 0x3c($a2)
/* 3BA2F8 E00BC2C8 46800021 */  cvt.d.w   $f0, $f0
/* 3BA2FC E00BC2CC 46220002 */  mul.d     $f0, $f0, $f2
/* 3BA300 E00BC2D0 00000000 */  nop       
/* 3BA304 E00BC2D4 4620010D */  trunc.w.d $f4, $f0
/* 3BA308 E00BC2D8 E4C4003C */  swc1      $f4, 0x3c($a2)
.LE00BC2DC:
/* 3BA30C E00BC2DC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3BA310 E00BC2E0 03E00008 */  jr        $ra
/* 3BA314 E00BC2E4 27BD0018 */   addiu    $sp, $sp, 0x18

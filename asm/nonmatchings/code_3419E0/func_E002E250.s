.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E002E250
/* 341C30 E002E250 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 341C34 E002E254 AFBF0010 */  sw        $ra, 0x10($sp)
/* 341C38 E002E258 8C85000C */  lw        $a1, 0xc($a0)
/* 341C3C E002E25C 8CA20038 */  lw        $v0, 0x38($a1)
/* 341C40 E002E260 8CA3003C */  lw        $v1, 0x3c($a1)
/* 341C44 E002E264 00021080 */  sll       $v0, $v0, 2
/* 341C48 E002E268 3C01E003 */  lui       $at, %hi(D_E002E754)
/* 341C4C E002E26C 00220821 */  addu      $at, $at, $v0
/* 341C50 E002E270 8C22E754 */  lw        $v0, %lo(D_E002E754)($at)
/* 341C54 E002E274 00431021 */  addu      $v0, $v0, $v1
/* 341C58 E002E278 80420000 */  lb        $v0, ($v0)
/* 341C5C E002E27C 24630001 */  addiu     $v1, $v1, 1
/* 341C60 E002E280 ACA3003C */  sw        $v1, 0x3c($a1)
/* 341C64 E002E284 04410005 */  bgez      $v0, .LE002E29C
/* 341C68 E002E288 ACA20040 */   sw       $v0, 0x40($a1)
/* 341C6C E002E28C 0C080128 */  jal       func_E02004A0
/* 341C70 E002E290 00000000 */   nop      
/* 341C74 E002E294 0800B8C9 */  j         .LE002E324
/* 341C78 E002E298 00000000 */   nop      
.LE002E29C:
/* 341C7C E002E29C 8C820008 */  lw        $v0, 8($a0)
/* 341C80 E002E2A0 24060001 */  addiu     $a2, $zero, 1
/* 341C84 E002E2A4 00C2102A */  slt       $v0, $a2, $v0
/* 341C88 E002E2A8 1040001E */  beqz      $v0, .LE002E324
/* 341C8C E002E2AC 24A50044 */   addiu    $a1, $a1, 0x44
/* 341C90 E002E2B0 24A30008 */  addiu     $v1, $a1, 8
.LE002E2B4:
/* 341C94 E002E2B4 C46A0010 */  lwc1      $f10, 0x10($v1)
/* 341C98 E002E2B8 C4600014 */  lwc1      $f0, 0x14($v1)
/* 341C9C E002E2BC 46005280 */  add.s     $f10, $f10, $f0
/* 341CA0 E002E2C0 C468000C */  lwc1      $f8, 0xc($v1)
/* 341CA4 E002E2C4 460A4200 */  add.s     $f8, $f8, $f10
/* 341CA8 E002E2C8 C4600008 */  lwc1      $f0, 8($v1)
/* 341CAC E002E2CC 46080000 */  add.s     $f0, $f0, $f8
/* 341CB0 E002E2D0 C4620028 */  lwc1      $f2, 0x28($v1)
/* 341CB4 E002E2D4 46020082 */  mul.s     $f2, $f0, $f2
/* 341CB8 E002E2D8 00000000 */  nop       
/* 341CBC E002E2DC E4600008 */  swc1      $f0, 8($v1)
/* 341CC0 E002E2E0 46000186 */  mov.s     $f6, $f0
/* 341CC4 E002E2E4 C460002C */  lwc1      $f0, 0x2c($v1)
/* 341CC8 E002E2E8 46003182 */  mul.s     $f6, $f6, $f0
/* 341CCC E002E2EC 00000000 */  nop       
/* 341CD0 E002E2F0 C464FFFC */  lwc1      $f4, -4($v1)
/* 341CD4 E002E2F4 C4600000 */  lwc1      $f0, ($v1)
/* 341CD8 E002E2F8 46022100 */  add.s     $f4, $f4, $f2
/* 341CDC E002E2FC 24C60001 */  addiu     $a2, $a2, 1
/* 341CE0 E002E300 E46A0010 */  swc1      $f10, 0x10($v1)
/* 341CE4 E002E304 46060000 */  add.s     $f0, $f0, $f6
/* 341CE8 E002E308 E468000C */  swc1      $f8, 0xc($v1)
/* 341CEC E002E30C E464FFFC */  swc1      $f4, -4($v1)
/* 341CF0 E002E310 E4600000 */  swc1      $f0, ($v1)
/* 341CF4 E002E314 8C820008 */  lw        $v0, 8($a0)
/* 341CF8 E002E318 00C2102A */  slt       $v0, $a2, $v0
/* 341CFC E002E31C 1440FFE5 */  bnez      $v0, .LE002E2B4
/* 341D00 E002E320 24630044 */   addiu    $v1, $v1, 0x44
.LE002E324:
/* 341D04 E002E324 8FBF0010 */  lw        $ra, 0x10($sp)
/* 341D08 E002E328 03E00008 */  jr        $ra
/* 341D0C E002E32C 27BD0018 */   addiu    $sp, $sp, 0x18

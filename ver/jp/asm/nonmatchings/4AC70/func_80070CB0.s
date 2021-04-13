.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070CB0
/* 4C0B0 80070CB0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C0B4 80070CB4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C0B8 80070CB8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C0BC 80070CBC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C0C0 80070CC0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C0C4 80070CC4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C0C8 80070CC8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C0CC 80070CCC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C0D0 80070CD0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C0D4 80070CD4 0C016885 */  jal       func_8005A214
/* 4C0D8 80070CD8 24040036 */   addiu    $a0, $zero, 0x36
/* 4C0DC 80070CDC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C0E0 80070CE0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C0E4 80070CE4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C0E8 80070CE8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C0EC 80070CEC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C0F0 80070CF0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C0F4 80070CF4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C0F8 80070CF8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C0FC 80070CFC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C100 80070D00 3C018008 */  lui       $at, %hi(D_8007F6F0)
/* 4C104 80070D04 8C21F6F0 */  lw        $at, %lo(D_8007F6F0)($at)
/* 4C108 80070D08 00200008 */  jr        $at
/* 4C10C 80070D0C 00000000 */   nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D42AC
/* F8C5C 802D42AC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F8C60 802D42B0 AFB10014 */  sw        $s1, 0x14($sp)
/* F8C64 802D42B4 0000882D */  daddu     $s1, $zero, $zero
/* F8C68 802D42B8 AFB20018 */  sw        $s2, 0x18($sp)
/* F8C6C 802D42BC 3C12802E */  lui       $s2, %hi(D_802DB7C0)
/* F8C70 802D42C0 2652B7C0 */  addiu     $s2, $s2, %lo(D_802DB7C0)
/* F8C74 802D42C4 AFBF001C */  sw        $ra, 0x1c($sp)
/* F8C78 802D42C8 AFB00010 */  sw        $s0, 0x10($sp)
/* F8C7C 802D42CC 8E430000 */  lw        $v1, ($s2)
.L802D42D0:
/* F8C80 802D42D0 8C700000 */  lw        $s0, ($v1)
/* F8C84 802D42D4 8E020000 */  lw        $v0, ($s0)
/* F8C88 802D42D8 04400006 */  bltz      $v0, .L802D42F4
/* F8C8C 802D42DC 2A220040 */   slti     $v0, $s1, 0x40
/* F8C90 802D42E0 26310001 */  addiu     $s1, $s1, 1
/* F8C94 802D42E4 2A220040 */  slti      $v0, $s1, 0x40
/* F8C98 802D42E8 1440FFF9 */  bnez      $v0, .L802D42D0
/* F8C9C 802D42EC 24630004 */   addiu    $v1, $v1, 4
/* F8CA0 802D42F0 2A220040 */  slti      $v0, $s1, 0x40
.L802D42F4:
/* F8CA4 802D42F4 10400015 */  beqz      $v0, .L802D434C
/* F8CA8 802D42F8 0000102D */   daddu    $v0, $zero, $zero
/* F8CAC 802D42FC 0C048379 */  jal       ALT_load_entity_model
/* F8CB0 802D4300 00000000 */   nop
/* F8CB4 802D4304 3C013F80 */  lui       $at, 0x3f80
/* F8CB8 802D4308 44810000 */  mtc1      $at, $f0
/* F8CBC 802D430C AE020000 */  sw        $v0, ($s0)
/* F8CC0 802D4310 0040202D */  daddu     $a0, $v0, $zero
/* F8CC4 802D4314 AE000004 */  sw        $zero, 4($s0)
/* F8CC8 802D4318 AE000008 */  sw        $zero, 8($s0)
/* F8CCC 802D431C AE00000C */  sw        $zero, 0xc($s0)
/* F8CD0 802D4320 AE000010 */  sw        $zero, 0x10($s0)
/* F8CD4 802D4324 AE000014 */  sw        $zero, 0x14($s0)
/* F8CD8 802D4328 AE000018 */  sw        $zero, 0x18($s0)
/* F8CDC 802D432C E600001C */  swc1      $f0, 0x1c($s0)
/* F8CE0 802D4330 E6000020 */  swc1      $f0, 0x20($s0)
/* F8CE4 802D4334 0C0483C1 */  jal       exec_entity_model_commandlist
/* F8CE8 802D4338 E6000024 */   swc1     $f0, 0x24($s0)
/* F8CEC 802D433C 8E430000 */  lw        $v1, ($s2)
/* F8CF0 802D4340 00111080 */  sll       $v0, $s1, 2
/* F8CF4 802D4344 00431021 */  addu      $v0, $v0, $v1
/* F8CF8 802D4348 8C420000 */  lw        $v0, ($v0)
.L802D434C:
/* F8CFC 802D434C 8FBF001C */  lw        $ra, 0x1c($sp)
/* F8D00 802D4350 8FB20018 */  lw        $s2, 0x18($sp)
/* F8D04 802D4354 8FB10014 */  lw        $s1, 0x14($sp)
/* F8D08 802D4358 8FB00010 */  lw        $s0, 0x10($sp)
/* F8D0C 802D435C 03E00008 */  jr        $ra
/* F8D10 802D4360 27BD0020 */   addiu    $sp, $sp, 0x20

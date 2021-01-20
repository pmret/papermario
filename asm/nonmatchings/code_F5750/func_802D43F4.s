.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D43F4
/* F8DA4 802D43F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F8DA8 802D43F8 3C02802E */  lui       $v0, %hi(D_802DB7C0)
/* F8DAC 802D43FC 8C42B7C0 */  lw        $v0, %lo(D_802DB7C0)($v0)
/* F8DB0 802D4400 00042080 */  sll       $a0, $a0, 2
/* F8DB4 802D4404 AFBF0014 */  sw        $ra, 0x14($sp)
/* F8DB8 802D4408 AFB00010 */  sw        $s0, 0x10($sp)
/* F8DBC 802D440C 00822021 */  addu      $a0, $a0, $v0
/* F8DC0 802D4410 8C900000 */  lw        $s0, ($a0)
/* F8DC4 802D4414 0C048B7F */  jal       free_entity_model_by_index
/* F8DC8 802D4418 8E040000 */   lw       $a0, ($s0)
/* F8DCC 802D441C 2402FFFF */  addiu     $v0, $zero, -1
/* F8DD0 802D4420 AE020000 */  sw        $v0, ($s0)
/* F8DD4 802D4424 8FBF0014 */  lw        $ra, 0x14($sp)
/* F8DD8 802D4428 8FB00010 */  lw        $s0, 0x10($sp)
/* F8DDC 802D442C 03E00008 */  jr        $ra
/* F8DE0 802D4430 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC00C_E2E93C
/* E2E93C 802BC00C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E2E940 802BC010 AFBF0018 */  sw        $ra, 0x18($sp)
/* E2E944 802BC014 C482004C */  lwc1      $f2, 0x4c($a0)
/* E2E948 802BC018 3C0141F0 */  lui       $at, 0x41f0
/* E2E94C 802BC01C 44810000 */  mtc1      $at, $f0
/* E2E950 802BC020 24020013 */  addiu     $v0, $zero, 0x13
/* E2E954 802BC024 AFA20010 */  sw        $v0, 0x10($sp)
/* E2E958 802BC028 AFA00014 */  sw        $zero, 0x14($sp)
/* E2E95C 802BC02C 46001080 */  add.s     $f2, $f2, $f0
/* E2E960 802BC030 8C850048 */  lw        $a1, 0x48($a0)
/* E2E964 802BC034 8C870050 */  lw        $a3, 0x50($a0)
/* E2E968 802BC038 44061000 */  mfc1      $a2, $f2
/* E2E96C 802BC03C 0C04C6A5 */  jal       make_item_entity_nodelay
/* E2E970 802BC040 24040157 */   addiu    $a0, $zero, 0x157
/* E2E974 802BC044 8FBF0018 */  lw        $ra, 0x18($sp)
/* E2E978 802BC048 03E00008 */  jr        $ra
/* E2E97C 802BC04C 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243650_9ABA40
/* 9ABA40 80243650 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 9ABA44 80243654 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9ABA48 80243658 0080982D */  daddu     $s3, $a0, $zero
/* 9ABA4C 8024365C AFBF0048 */  sw        $ra, 0x48($sp)
/* 9ABA50 80243660 AFB50044 */  sw        $s5, 0x44($sp)
/* 9ABA54 80243664 AFB40040 */  sw        $s4, 0x40($sp)
/* 9ABA58 80243668 AFB20038 */  sw        $s2, 0x38($sp)
/* 9ABA5C 8024366C AFB10034 */  sw        $s1, 0x34($sp)
/* 9ABA60 80243670 AFB00030 */  sw        $s0, 0x30($sp)
/* 9ABA64 80243674 8E720148 */  lw        $s2, 0x148($s3)
/* 9ABA68 80243678 86440008 */  lh        $a0, 8($s2)
/* 9ABA6C 8024367C 8E70000C */  lw        $s0, 0xc($s3)
/* 9ABA70 80243680 0C00EABB */  jal       get_npc_unsafe
/* 9ABA74 80243684 00A0882D */   daddu    $s1, $a1, $zero
/* 9ABA78 80243688 0260202D */  daddu     $a0, $s3, $zero
/* 9ABA7C 8024368C 8E050000 */  lw        $a1, ($s0)
/* 9ABA80 80243690 0C0B1EAF */  jal       get_variable
/* 9ABA84 80243694 0040A82D */   daddu    $s5, $v0, $zero
/* 9ABA88 80243698 AFA00010 */  sw        $zero, 0x10($sp)
/* 9ABA8C 8024369C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9ABA90 802436A0 8C630030 */  lw        $v1, 0x30($v1)
/* 9ABA94 802436A4 AFA30014 */  sw        $v1, 0x14($sp)
/* 9ABA98 802436A8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9ABA9C 802436AC 8C63001C */  lw        $v1, 0x1c($v1)
/* 9ABAA0 802436B0 AFA30018 */  sw        $v1, 0x18($sp)
/* 9ABAA4 802436B4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9ABAA8 802436B8 8C630024 */  lw        $v1, 0x24($v1)
/* 9ABAAC 802436BC AFA3001C */  sw        $v1, 0x1c($sp)
/* 9ABAB0 802436C0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9ABAB4 802436C4 8C630028 */  lw        $v1, 0x28($v1)
/* 9ABAB8 802436C8 27B40010 */  addiu     $s4, $sp, 0x10
/* 9ABABC 802436CC AFA30020 */  sw        $v1, 0x20($sp)
/* 9ABAC0 802436D0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9ABAC4 802436D4 3C0142F0 */  lui       $at, 0x42f0
/* 9ABAC8 802436D8 44810000 */  mtc1      $at, $f0
/* 9ABACC 802436DC 8C63002C */  lw        $v1, 0x2c($v1)
/* 9ABAD0 802436E0 0040802D */  daddu     $s0, $v0, $zero
/* 9ABAD4 802436E4 E7A00028 */  swc1      $f0, 0x28($sp)
/* 9ABAD8 802436E8 A7A0002C */  sh        $zero, 0x2c($sp)
/* 9ABADC 802436EC 12200009 */  beqz      $s1, .L80243714
/* 9ABAE0 802436F0 AFA30024 */   sw       $v1, 0x24($sp)
/* 9ABAE4 802436F4 02A0202D */  daddu     $a0, $s5, $zero
/* 9ABAE8 802436F8 0240282D */  daddu     $a1, $s2, $zero
/* 9ABAEC 802436FC 0260302D */  daddu     $a2, $s3, $zero
/* 9ABAF0 80243700 0C090C00 */  jal       func_80243000_9AB3F0
/* 9ABAF4 80243704 0200382D */   daddu    $a3, $s0, $zero
/* 9ABAF8 80243708 86A200A8 */  lh        $v0, 0xa8($s5)
/* 9ABAFC 8024370C AE42008C */  sw        $v0, 0x8c($s2)
/* 9ABB00 80243710 AE600070 */  sw        $zero, 0x70($s3)
.L80243714:
/* 9ABB04 80243714 2402FFFD */  addiu     $v0, $zero, -3
/* 9ABB08 80243718 A2A200AB */  sb        $v0, 0xab($s5)
/* 9ABB0C 8024371C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 9ABB10 80243720 30620004 */  andi      $v0, $v1, 4
/* 9ABB14 80243724 10400007 */  beqz      $v0, .L80243744
/* 9ABB18 80243728 00000000 */   nop      
/* 9ABB1C 8024372C 824200B4 */  lb        $v0, 0xb4($s2)
/* 9ABB20 80243730 14400052 */  bnez      $v0, .L8024387C
/* 9ABB24 80243734 0000102D */   daddu    $v0, $zero, $zero
/* 9ABB28 80243738 2402FFFB */  addiu     $v0, $zero, -5
/* 9ABB2C 8024373C 00621024 */  and       $v0, $v1, $v0
/* 9ABB30 80243740 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80243744:
/* 9ABB34 80243744 8E630070 */  lw        $v1, 0x70($s3)
/* 9ABB38 80243748 2C620010 */  sltiu     $v0, $v1, 0x10
/* 9ABB3C 8024374C 1040004A */  beqz      $v0, .L80243878
/* 9ABB40 80243750 00031080 */   sll      $v0, $v1, 2
/* 9ABB44 80243754 3C018024 */  lui       $at, 0x8024
/* 9ABB48 80243758 00220821 */  addu      $at, $at, $v0
/* 9ABB4C 8024375C 8C2262C8 */  lw        $v0, 0x62c8($at)
/* 9ABB50 80243760 00400008 */  jr        $v0
/* 9ABB54 80243764 00000000 */   nop      
/* 9ABB58 80243768 0260202D */  daddu     $a0, $s3, $zero
/* 9ABB5C 8024376C 0200282D */  daddu     $a1, $s0, $zero
/* 9ABB60 80243770 0C090786 */  jal       func_80241E18_9AA208
/* 9ABB64 80243774 0280302D */   daddu    $a2, $s4, $zero
/* 9ABB68 80243778 0260202D */  daddu     $a0, $s3, $zero
/* 9ABB6C 8024377C 0200282D */  daddu     $a1, $s0, $zero
/* 9ABB70 80243780 0C0907F2 */  jal       func_80241FC8_9AA3B8
/* 9ABB74 80243784 0280302D */   daddu    $a2, $s4, $zero
/* 9ABB78 80243788 8E630070 */  lw        $v1, 0x70($s3)
/* 9ABB7C 8024378C 24020002 */  addiu     $v0, $zero, 2
/* 9ABB80 80243790 1462003A */  bne       $v1, $v0, .L8024387C
/* 9ABB84 80243794 0000102D */   daddu    $v0, $zero, $zero
/* 9ABB88 80243798 0260202D */  daddu     $a0, $s3, $zero
/* 9ABB8C 8024379C 0200282D */  daddu     $a1, $s0, $zero
/* 9ABB90 802437A0 0C09097C */  jal       func_802425F0_9AA9E0
/* 9ABB94 802437A4 0280302D */   daddu    $a2, $s4, $zero
/* 9ABB98 802437A8 0260202D */  daddu     $a0, $s3, $zero
/* 9ABB9C 802437AC 0200282D */  daddu     $a1, $s0, $zero
/* 9ABBA0 802437B0 0C0909AC */  jal       func_802426B0_9AAAA0
/* 9ABBA4 802437B4 0280302D */   daddu    $a2, $s4, $zero
/* 9ABBA8 802437B8 8E630070 */  lw        $v1, 0x70($s3)
/* 9ABBAC 802437BC 2402000A */  addiu     $v0, $zero, 0xa
/* 9ABBB0 802437C0 1462002E */  bne       $v1, $v0, .L8024387C
/* 9ABBB4 802437C4 0000102D */   daddu    $v0, $zero, $zero
/* 9ABBB8 802437C8 0260202D */  daddu     $a0, $s3, $zero
/* 9ABBBC 802437CC 0200282D */  daddu     $a1, $s0, $zero
/* 9ABBC0 802437D0 0C090A7D */  jal       UnkNpcAIFunc2
/* 9ABBC4 802437D4 0280302D */   daddu    $a2, $s4, $zero
/* 9ABBC8 802437D8 8E630070 */  lw        $v1, 0x70($s3)
/* 9ABBCC 802437DC 2402000B */  addiu     $v0, $zero, 0xb
/* 9ABBD0 802437E0 14620026 */  bne       $v1, $v0, .L8024387C
/* 9ABBD4 802437E4 0000102D */   daddu    $v0, $zero, $zero
/* 9ABBD8 802437E8 0260202D */  daddu     $a0, $s3, $zero
/* 9ABBDC 802437EC 0200282D */  daddu     $a1, $s0, $zero
/* 9ABBE0 802437F0 0C090A9B */  jal       func_80242A6C_9AAE5C
/* 9ABBE4 802437F4 0280302D */   daddu    $a2, $s4, $zero
/* 9ABBE8 802437F8 8E630070 */  lw        $v1, 0x70($s3)
/* 9ABBEC 802437FC 2402000C */  addiu     $v0, $zero, 0xc
/* 9ABBF0 80243800 1462001E */  bne       $v1, $v0, .L8024387C
/* 9ABBF4 80243804 0000102D */   daddu    $v0, $zero, $zero
/* 9ABBF8 80243808 0260202D */  daddu     $a0, $s3, $zero
/* 9ABBFC 8024380C 0200282D */  daddu     $a1, $s0, $zero
/* 9ABC00 80243810 0C090CC4 */  jal       func_80243310_9AB700
/* 9ABC04 80243814 0280302D */   daddu    $a2, $s4, $zero
/* 9ABC08 80243818 8E630070 */  lw        $v1, 0x70($s3)
/* 9ABC0C 8024381C 2402000D */  addiu     $v0, $zero, 0xd
/* 9ABC10 80243820 14620016 */  bne       $v1, $v0, .L8024387C
/* 9ABC14 80243824 0000102D */   daddu    $v0, $zero, $zero
/* 9ABC18 80243828 0260202D */  daddu     $a0, $s3, $zero
/* 9ABC1C 8024382C 0200282D */  daddu     $a1, $s0, $zero
/* 9ABC20 80243830 0C090D0E */  jal       func_80243438_9AB828
/* 9ABC24 80243834 0280302D */   daddu    $a2, $s4, $zero
/* 9ABC28 80243838 8E630070 */  lw        $v1, 0x70($s3)
/* 9ABC2C 8024383C 2402000E */  addiu     $v0, $zero, 0xe
/* 9ABC30 80243840 1462000E */  bne       $v1, $v0, .L8024387C
/* 9ABC34 80243844 0000102D */   daddu    $v0, $zero, $zero
/* 9ABC38 80243848 0260202D */  daddu     $a0, $s3, $zero
/* 9ABC3C 8024384C 0200282D */  daddu     $a1, $s0, $zero
/* 9ABC40 80243850 0C090D3D */  jal       func_802434F4_9AB8E4
/* 9ABC44 80243854 0280302D */   daddu    $a2, $s4, $zero
/* 9ABC48 80243858 8E630070 */  lw        $v1, 0x70($s3)
/* 9ABC4C 8024385C 2402000F */  addiu     $v0, $zero, 0xf
/* 9ABC50 80243860 14620006 */  bne       $v1, $v0, .L8024387C
/* 9ABC54 80243864 0000102D */   daddu    $v0, $zero, $zero
/* 9ABC58 80243868 0260202D */  daddu     $a0, $s3, $zero
/* 9ABC5C 8024386C 0200282D */  daddu     $a1, $s0, $zero
/* 9ABC60 80243870 0C090D83 */  jal       UnkDurationCheck
/* 9ABC64 80243874 0280302D */   daddu    $a2, $s4, $zero
.L80243878:
/* 9ABC68 80243878 0000102D */  daddu     $v0, $zero, $zero
.L8024387C:
/* 9ABC6C 8024387C 8FBF0048 */  lw        $ra, 0x48($sp)
/* 9ABC70 80243880 8FB50044 */  lw        $s5, 0x44($sp)
/* 9ABC74 80243884 8FB40040 */  lw        $s4, 0x40($sp)
/* 9ABC78 80243888 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9ABC7C 8024388C 8FB20038 */  lw        $s2, 0x38($sp)
/* 9ABC80 80243890 8FB10034 */  lw        $s1, 0x34($sp)
/* 9ABC84 80243894 8FB00030 */  lw        $s0, 0x30($sp)
/* 9ABC88 80243898 03E00008 */  jr        $ra
/* 9ABC8C 8024389C 27BD0050 */   addiu    $sp, $sp, 0x50

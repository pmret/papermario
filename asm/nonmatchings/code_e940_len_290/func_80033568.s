.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80033568
/* 00E968 80033568 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00E96C 8003356C AFB00010 */  sw    $s0, 0x10($sp)
/* 00E970 80033570 3C108007 */  lui   $s0, 0x8007
/* 00E974 80033574 2610419C */  addiu $s0, $s0, 0x419c
/* 00E978 80033578 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00E97C 8003357C 8E040000 */  lw    $a0, ($s0)
/* 00E980 80033580 808200AC */  lb    $v0, 0xac($a0)
/* 00E984 80033584 908300AC */  lbu   $v1, 0xac($a0)
/* 00E988 80033588 10400003 */  beqz  $v0, .L80033598
/* 00E98C 8003358C 2462FFFF */   addiu $v0, $v1, -1
/* 00E990 80033590 0800CDDE */  j     .L80033778
/* 00E994 80033594 A08200AC */   sb    $v0, 0xac($a0)

.L80033598:
/* 00E998 80033598 3C01800A */  lui   $at, 0x800a
/* 00E99C 8003359C AC20A650 */  sw    $zero, -0x59b0($at)
/* 00E9A0 800335A0 A4800086 */  sh    $zero, 0x86($a0)
/* 00E9A4 800335A4 A0800070 */  sb    $zero, 0x70($a0)
/* 00E9A8 800335A8 8E020000 */  lw    $v0, ($s0)
/* 00E9AC 800335AC 2403FFFF */  addiu $v1, $zero, -1
/* 00E9B0 800335B0 A4830088 */  sh    $v1, 0x88($a0)
/* 00E9B4 800335B4 A480008C */  sh    $zero, 0x8c($a0)
/* 00E9B8 800335B8 A480008E */  sh    $zero, 0x8e($a0)
/* 00E9BC 800335BC A0400076 */  sb    $zero, 0x76($v0)
/* 00E9C0 800335C0 8E020000 */  lw    $v0, ($s0)
/* 00E9C4 800335C4 A0400078 */  sb    $zero, 0x78($v0)
/* 00E9C8 800335C8 8E020000 */  lw    $v0, ($s0)
/* 00E9CC 800335CC A040007D */  sb    $zero, 0x7d($v0)
/* 00E9D0 800335D0 8E020000 */  lw    $v0, ($s0)
/* 00E9D4 800335D4 A04300A8 */  sb    $v1, 0xa8($v0)
/* 00E9D8 800335D8 8E020000 */  lw    $v0, ($s0)
/* 00E9DC 800335DC A04000AA */  sb    $zero, 0xaa($v0)
/* 00E9E0 800335E0 8E020000 */  lw    $v0, ($s0)
/* 00E9E4 800335E4 A04300A9 */  sb    $v1, 0xa9($v0)
/* 00E9E8 800335E8 8E020000 */  lw    $v0, ($s0)
/* 00E9EC 800335EC 0C00AB00 */  jal   general_heap_create
/* 00E9F0 800335F0 A0400071 */   sb    $zero, 0x71($v0)
/* 00E9F4 800335F4 0C047624 */  jal   func_8011D890
/* 00E9F8 800335F8 00000000 */   nop   
/* 00E9FC 800335FC 0C048C2E */  jal   func_801230B8
/* 00EA00 80033600 00000000 */   nop   
/* 00EA04 80033604 0C0B0C77 */  jal   clear_script_list
/* 00EA08 80033608 00000000 */   nop   
/* 00EA0C 8003360C 0C00B7BD */  jal   create_cameras_a
/* 00EA10 80033610 00000000 */   nop   
/* 00EA14 80033614 0C0B763E */  jal   func_802DD8F8
/* 00EA18 80033618 0000202D */   daddu $a0, $zero, $zero
/* 00EA1C 8003361C 0C0482EC */  jal   func_80120BB0
/* 00EA20 80033620 00000000 */   nop   
/* 00EA24 80033624 0C047889 */  jal   func_8011E224
/* 00EA28 80033628 00000000 */   nop   
/* 00EA2C 8003362C 0C045751 */  jal   clear_model_data
/* 00EA30 80033630 00000000 */   nop   
/* 00EA34 80033634 0C052010 */  jal   func_80148040
/* 00EA38 80033638 00000000 */   nop   
/* 00EA3C 8003363C 0C05177E */  jal   func_80145DF8
/* 00EA40 80033640 00000000 */   nop   
/* 00EA44 80033644 0000202D */  daddu $a0, $zero, $zero
/* 00EA48 80033648 0C0514BA */  jal   func_801452E8
/* 00EA4C 8003364C 0080282D */   daddu $a1, $a0, $zero
/* 00EA50 80033650 0C050440 */  jal   func_80141100
/* 00EA54 80033654 00000000 */   nop   
/* 00EA58 80033658 0C0515A0 */  jal   clear_trigger_data
/* 00EA5C 8003365C 00000000 */   nop   
/* 00EA60 80033660 0C048D9D */  jal   clear_printers
/* 00EA64 80033664 00000000 */   nop   
/* 00EA68 80033668 0C04432E */  jal   func_80110CB8
/* 00EA6C 8003366C 0000202D */   daddu $a0, $zero, $zero
/* 00EA70 80033670 0C04E042 */  jal   func_80138108
/* 00EA74 80033674 00000000 */   nop   
/* 00EA78 80033678 0C037F14 */  jal   clear_player_status
/* 00EA7C 8003367C 00000000 */   nop   
/* 00EA80 80033680 0C00E12F */  jal   func_800384BC
/* 00EA84 80033684 00000000 */   nop   
/* 00EA88 80033688 0C039CE8 */  jal   clear_player_data
/* 00EA8C 8003368C 00000000 */   nop   
/* 00EA90 80033690 0C01CACC */  jal   func_80072B30
/* 00EA94 80033694 00000000 */   nop   
/* 00EA98 80033698 0C00F8CE */  jal   func_8003E338
/* 00EA9C 8003369C 00000000 */   nop   
/* 00EAA0 800336A0 0C016727 */  jal   func_80059C9C
/* 00EAA4 800336A4 00000000 */   nop   
/* 00EAA8 800336A8 0C04C3FC */  jal   clear_item_entity_data
/* 00EAAC 800336AC 00000000 */   nop   
/* 00EAB0 800336B0 0C0514C8 */  jal   clear_saved_variables
/* 00EAB4 800336B4 00000000 */   nop   
/* 00EAB8 800336B8 0C016BE5 */  jal   initialize_collision
/* 00EABC 800336BC 00000000 */   nop   
/* 00EAC0 800336C0 0C052B02 */  jal   func_8014AC08
/* 00EAC4 800336C4 00000000 */   nop   
/* 00EAC8 800336C8 0C051CFC */  jal   func_801473F0
/* 00EACC 800336CC 00000000 */   nop   
/* 00EAD0 800336D0 0C03AD60 */  jal   func_800EB580
/* 00EAD4 800336D4 00000000 */   nop   
/* 00EAD8 800336D8 0C052586 */  jal   func_80149618
/* 00EADC 800336DC 00000000 */   nop   
/* 00EAE0 800336E0 0C05294B */  jal   func_8014A52C
/* 00EAE4 800336E4 00000000 */   nop   
/* 00EAE8 800336E8 0C00AE90 */  jal   func_8002BA40
/* 00EAEC 800336EC 00000000 */   nop   
/* 00EAF0 800336F0 0000202D */  daddu $a0, $zero, $zero
/* 00EAF4 800336F4 24060004 */  addiu $a2, $zero, 4
/* 00EAF8 800336F8 2405000F */  addiu $a1, $zero, 0xf
/* 00EAFC 800336FC 8E030000 */  lw    $v1, ($s0)
.L80033700:
/* 00EB00 80033700 A4660050 */  sh    $a2, 0x50($v1)
/* 00EB04 80033704 A4650048 */  sh    $a1, 0x48($v1)
/* 00EB08 80033708 24840001 */  addiu $a0, $a0, 1
/* 00EB0C 8003370C 28820004 */  slti  $v0, $a0, 4
/* 00EB10 80033710 1440FFFB */  bnez  $v0, .L80033700
/* 00EB14 80033714 24630002 */   addiu $v1, $v1, 2
/* 00EB18 80033718 0C00ABF6 */  jal   fio_has_valid_backup
/* 00EB1C 8003371C 00000000 */   nop   
/* 00EB20 80033720 3C02800E */  lui   $v0, 0x800e
/* 00EB24 80033724 8C429620 */  lw    $v0, -0x69e0($v0)
/* 00EB28 80033728 14400007 */  bnez  $v0, .L80033748
/* 00EB2C 8003372C 24020001 */   addiu $v0, $zero, 1
/* 00EB30 80033730 3C038007 */  lui   $v1, 0x8007
/* 00EB34 80033734 8C63419C */  lw    $v1, 0x419c($v1)
/* 00EB38 80033738 0C015857 */  jal   func_8005615C
/* 00EB3C 8003373C A06200AB */   sb    $v0, 0xab($v1)
/* 00EB40 80033740 0800CDD7 */  j     .L8003375C
/* 00EB44 80033744 24040001 */   addiu $a0, $zero, 1

.L80033748:
/* 00EB48 80033748 3C028007 */  lui   $v0, 0x8007
/* 00EB4C 8003374C 8C42419C */  lw    $v0, 0x419c($v0)
/* 00EB50 80033750 0C015860 */  jal   func_80056180
/* 00EB54 80033754 A04000AB */   sb    $zero, 0xab($v0)
/* 00EB58 80033758 24040001 */  addiu $a0, $zero, 1
.L8003375C:
/* 00EB5C 8003375C 3C02800A */  lui   $v0, 0x800a
/* 00EB60 80033760 2442A650 */  addiu $v0, $v0, -0x59b0
/* 00EB64 80033764 8C430000 */  lw    $v1, ($v0)
/* 00EB68 80033768 2405FFF7 */  addiu $a1, $zero, -9
/* 00EB6C 8003376C 00651824 */  and   $v1, $v1, $a1
/* 00EB70 80033770 0C00CD3C */  jal   set_game_mode
/* 00EB74 80033774 AC430000 */   sw    $v1, ($v0)
.L80033778:
/* 00EB78 80033778 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00EB7C 8003377C 8FB00010 */  lw    $s0, 0x10($sp)
/* 00EB80 80033780 03E00008 */  jr    $ra
/* 00EB84 80033784 27BD0018 */   addiu $sp, $sp, 0x18


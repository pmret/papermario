.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel step_init_state
/* E968 80033568 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E96C 8003356C AFB00010 */  sw        $s0, 0x10($sp)
/* E970 80033570 3C108007 */  lui       $s0, 0x8007
/* E974 80033574 2610419C */  addiu     $s0, $s0, 0x419c
/* E978 80033578 AFBF0014 */  sw        $ra, 0x14($sp)
/* E97C 8003357C 8E040000 */  lw        $a0, ($s0)
/* E980 80033580 808200AC */  lb        $v0, 0xac($a0)
/* E984 80033584 908300AC */  lbu       $v1, 0xac($a0)
/* E988 80033588 10400003 */  beqz      $v0, .L80033598
/* E98C 8003358C 2462FFFF */   addiu    $v0, $v1, -1
/* E990 80033590 0800CDDE */  j         .L80033778
/* E994 80033594 A08200AC */   sb       $v0, 0xac($a0)
.L80033598:
/* E998 80033598 3C01800A */  lui       $at, 0x800a
/* E99C 8003359C AC20A650 */  sw        $zero, -0x59b0($at)
/* E9A0 800335A0 A4800086 */  sh        $zero, 0x86($a0)
/* E9A4 800335A4 A0800070 */  sb        $zero, 0x70($a0)
/* E9A8 800335A8 8E020000 */  lw        $v0, ($s0)
/* E9AC 800335AC 2403FFFF */  addiu     $v1, $zero, -1
/* E9B0 800335B0 A4830088 */  sh        $v1, 0x88($a0)
/* E9B4 800335B4 A480008C */  sh        $zero, 0x8c($a0)
/* E9B8 800335B8 A480008E */  sh        $zero, 0x8e($a0)
/* E9BC 800335BC A0400076 */  sb        $zero, 0x76($v0)
/* E9C0 800335C0 8E020000 */  lw        $v0, ($s0)
/* E9C4 800335C4 A0400078 */  sb        $zero, 0x78($v0)
/* E9C8 800335C8 8E020000 */  lw        $v0, ($s0)
/* E9CC 800335CC A040007D */  sb        $zero, 0x7d($v0)
/* E9D0 800335D0 8E020000 */  lw        $v0, ($s0)
/* E9D4 800335D4 A04300A8 */  sb        $v1, 0xa8($v0)
/* E9D8 800335D8 8E020000 */  lw        $v0, ($s0)
/* E9DC 800335DC A04000AA */  sb        $zero, 0xaa($v0)
/* E9E0 800335E0 8E020000 */  lw        $v0, ($s0)
/* E9E4 800335E4 A04300A9 */  sb        $v1, 0xa9($v0)
/* E9E8 800335E8 8E020000 */  lw        $v0, ($s0)
/* E9EC 800335EC 0C00AB00 */  jal       general_heap_create
/* E9F0 800335F0 A0400071 */   sb       $zero, 0x71($v0)
/* E9F4 800335F4 0C047624 */  jal       func_8011D890
/* E9F8 800335F8 00000000 */   nop      
/* E9FC 800335FC 0C048C2E */  jal       clear_dynamic_entity_list
/* EA00 80033600 00000000 */   nop      
/* EA04 80033604 0C0B0C77 */  jal       clear_script_list
/* EA08 80033608 00000000 */   nop      
/* EA0C 8003360C 0C00B7BD */  jal       create_cameras_a
/* EA10 80033610 00000000 */   nop      
/* EA14 80033614 0C0B763E */  jal       func_802DD8F8
/* EA18 80033618 0000202D */   daddu    $a0, $zero, $zero
/* EA1C 8003361C 0C0482EC */  jal       clear_virtual_models
/* EA20 80033620 00000000 */   nop      
/* EA24 80033624 0C047889 */  jal       func_8011E224
/* EA28 80033628 00000000 */   nop      
/* EA2C 8003362C 0C045751 */  jal       clear_model_data
/* EA30 80033630 00000000 */   nop      
/* EA34 80033634 0C052010 */  jal       func_80148040
/* EA38 80033638 00000000 */   nop      
/* EA3C 8003363C 0C05177E */  jal       func_80145DF8
/* EA40 80033640 00000000 */   nop      
/* EA44 80033644 0000202D */  daddu     $a0, $zero, $zero
/* EA48 80033648 0C0514BA */  jal       func_801452E8
/* EA4C 8003364C 0080282D */   daddu    $a1, $a0, $zero
/* EA50 80033650 0C050440 */  jal       func_80141100
/* EA54 80033654 00000000 */   nop      
/* EA58 80033658 0C0515A0 */  jal       clear_trigger_data
/* EA5C 8003365C 00000000 */   nop      
/* EA60 80033660 0C048D9D */  jal       clear_printers
/* EA64 80033664 00000000 */   nop      
/* EA68 80033668 0C04432E */  jal       clear_entity_data
/* EA6C 8003366C 0000202D */   daddu    $a0, $zero, $zero
/* EA70 80033670 0C04E042 */  jal       func_80138108
/* EA74 80033674 00000000 */   nop      
/* EA78 80033678 0C037F14 */  jal       clear_player_status
/* EA7C 8003367C 00000000 */   nop      
/* EA80 80033680 0C00E12F */  jal       clear_npcs
/* EA84 80033684 00000000 */   nop      
/* EA88 80033688 0C039CE8 */  jal       clear_player_data
/* EA8C 8003368C 00000000 */   nop      
/* EA90 80033690 0C01CACC */  jal       func_80072B30
/* EA94 80033694 00000000 */   nop      
/* EA98 80033698 0C00F8CE */  jal       func_8003E338
/* EA9C 8003369C 00000000 */   nop      
/* EAA0 800336A0 0C016727 */  jal       func_80059C9C
/* EAA4 800336A4 00000000 */   nop      
/* EAA8 800336A8 0C04C3FC */  jal       clear_item_entity_data
/* EAAC 800336AC 00000000 */   nop      
/* EAB0 800336B0 0C0514C8 */  jal       clear_saved_variables
/* EAB4 800336B4 00000000 */   nop      
/* EAB8 800336B8 0C016BE5 */  jal       initialize_collision
/* EABC 800336BC 00000000 */   nop      
/* EAC0 800336C0 0C052B02 */  jal       func_8014AC08
/* EAC4 800336C4 00000000 */   nop      
/* EAC8 800336C8 0C051CFC */  jal       func_801473F0
/* EACC 800336CC 00000000 */   nop      
/* EAD0 800336D0 0C03AD60 */  jal       partner_initialize_data
/* EAD4 800336D4 00000000 */   nop      
/* EAD8 800336D8 0C052586 */  jal       func_80149618
/* EADC 800336DC 00000000 */   nop      
/* EAE0 800336E0 0C05294B */  jal       func_8014A52C
/* EAE4 800336E4 00000000 */   nop      
/* EAE8 800336E8 0C00AE90 */  jal       initialize_curtains
/* EAEC 800336EC 00000000 */   nop      
/* EAF0 800336F0 0000202D */  daddu     $a0, $zero, $zero
/* EAF4 800336F4 24060004 */  addiu     $a2, $zero, 4
/* EAF8 800336F8 2405000F */  addiu     $a1, $zero, 0xf
/* EAFC 800336FC 8E030000 */  lw        $v1, ($s0)
.L80033700:
/* EB00 80033700 A4660050 */  sh        $a2, 0x50($v1)
/* EB04 80033704 A4650048 */  sh        $a1, 0x48($v1)
/* EB08 80033708 24840001 */  addiu     $a0, $a0, 1
/* EB0C 8003370C 28820004 */  slti      $v0, $a0, 4
/* EB10 80033710 1440FFFB */  bnez      $v0, .L80033700
/* EB14 80033714 24630002 */   addiu    $v1, $v1, 2
/* EB18 80033718 0C00ABF6 */  jal       fio_has_valid_backup
/* EB1C 8003371C 00000000 */   nop      
/* EB20 80033720 3C02800E */  lui       $v0, 0x800e
/* EB24 80033724 8C429620 */  lw        $v0, -0x69e0($v0)
/* EB28 80033728 14400007 */  bnez      $v0, .L80033748
/* EB2C 8003372C 24020001 */   addiu    $v0, $zero, 1
/* EB30 80033730 3C038007 */  lui       $v1, 0x8007
/* EB34 80033734 8C63419C */  lw        $v1, 0x419c($v1)
/* EB38 80033738 0C015857 */  jal       func_8005615C
/* EB3C 8003373C A06200AB */   sb       $v0, 0xab($v1)
/* EB40 80033740 0800CDD7 */  j         .L8003375C
/* EB44 80033744 24040001 */   addiu    $a0, $zero, 1
.L80033748:
/* EB48 80033748 3C028007 */  lui       $v0, 0x8007
/* EB4C 8003374C 8C42419C */  lw        $v0, 0x419c($v0)
/* EB50 80033750 0C015860 */  jal       func_80056180
/* EB54 80033754 A04000AB */   sb       $zero, 0xab($v0)
/* EB58 80033758 24040001 */  addiu     $a0, $zero, 1
.L8003375C:
/* EB5C 8003375C 3C02800A */  lui       $v0, 0x800a
/* EB60 80033760 2442A650 */  addiu     $v0, $v0, -0x59b0
/* EB64 80033764 8C430000 */  lw        $v1, ($v0)
/* EB68 80033768 2405FFF7 */  addiu     $a1, $zero, -9
/* EB6C 8003376C 00651824 */  and       $v1, $v1, $a1
/* EB70 80033770 0C00CD3C */  jal       set_game_mode
/* EB74 80033774 AC430000 */   sw       $v1, ($v0)
.L80033778:
/* EB78 80033778 8FBF0014 */  lw        $ra, 0x14($sp)
/* EB7C 8003377C 8FB00010 */  lw        $s0, 0x10($sp)
/* EB80 80033780 03E00008 */  jr        $ra
/* EB84 80033784 27BD0018 */   addiu    $sp, $sp, 0x18

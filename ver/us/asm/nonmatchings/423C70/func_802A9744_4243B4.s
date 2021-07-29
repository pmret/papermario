.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9744_4243B4
/* 4243B4 802A9744 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4243B8 802A9748 3C03802A */  lui       $v1, %hi(D_8029FBE0)
/* 4243BC 802A974C 2463FBE0 */  addiu     $v1, $v1, %lo(D_8029FBE0)
/* 4243C0 802A9750 AFB00018 */  sw        $s0, 0x18($sp)
/* 4243C4 802A9754 0060802D */  daddu     $s0, $v1, $zero
/* 4243C8 802A9758 AFB30024 */  sw        $s3, 0x24($sp)
/* 4243CC 802A975C 3C13800E */  lui       $s3, %hi(gBattleStatus)
/* 4243D0 802A9760 2673C070 */  addiu     $s3, $s3, %lo(gBattleStatus)
/* 4243D4 802A9764 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4243D8 802A9768 AFB40028 */  sw        $s4, 0x28($sp)
/* 4243DC 802A976C AFB20020 */  sw        $s2, 0x20($sp)
/* 4243E0 802A9770 AFB1001C */  sw        $s1, 0x1c($sp)
/* 4243E4 802A9774 8462006A */  lh        $v0, 0x6a($v1)
/* 4243E8 802A9778 14400004 */  bnez      $v0, .L802A978C
/* 4243EC 802A977C 0260A02D */   daddu    $s4, $s3, $zero
/* 4243F0 802A9780 8C640004 */  lw        $a0, 4($v1)
/* 4243F4 802A9784 0C0511EA */  jal       draw_hud_element_clipped
/* 4243F8 802A9788 00000000 */   nop
.L802A978C:
/* 4243FC 802A978C 8E110008 */  lw        $s1, 8($s0)
/* 424400 802A9790 0C0511EA */  jal       draw_hud_element_clipped
/* 424404 802A9794 0220202D */   daddu    $a0, $s1, $zero
/* 424408 802A9798 0220202D */  daddu     $a0, $s1, $zero
/* 42440C 802A979C 27A50010 */  addiu     $a1, $sp, 0x10
/* 424410 802A97A0 0C05126B */  jal       get_hud_element_render_pos
/* 424414 802A97A4 27A60014 */   addiu    $a2, $sp, 0x14
/* 424418 802A97A8 3C0451EB */  lui       $a0, 0x51eb
/* 42441C 802A97AC 96030044 */  lhu       $v1, 0x44($s0)
/* 424420 802A97B0 3484851F */  ori       $a0, $a0, 0x851f
/* 424424 802A97B4 00031C00 */  sll       $v1, $v1, 0x10
/* 424428 802A97B8 00031403 */  sra       $v0, $v1, 0x10
/* 42442C 802A97BC 00440018 */  mult      $v0, $a0
/* 424430 802A97C0 24070001 */  addiu     $a3, $zero, 1
/* 424434 802A97C4 8FA50014 */  lw        $a1, 0x14($sp)
/* 424438 802A97C8 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42443C 802A97CC 8FA40010 */  lw        $a0, 0x10($sp)
/* 424440 802A97D0 00004010 */  mfhi      $t0
/* 424444 802A97D4 00083143 */  sra       $a2, $t0, 5
/* 424448 802A97D8 00C33023 */  subu      $a2, $a2, $v1
/* 42444C 802A97DC 00063400 */  sll       $a2, $a2, 0x10
/* 424450 802A97E0 0C09A1E6 */  jal       func_80268798
/* 424454 802A97E4 00063403 */   sra      $a2, $a2, 0x10
/* 424458 802A97E8 8E040010 */  lw        $a0, 0x10($s0)
/* 42445C 802A97EC 0C0511EA */  jal       draw_hud_element_clipped
/* 424460 802A97F0 00000000 */   nop
/* 424464 802A97F4 86020064 */  lh        $v0, 0x64($s0)
/* 424468 802A97F8 8E11000C */  lw        $s1, 0xc($s0)
/* 42446C 802A97FC 1440000D */  bnez      $v0, .L802A9834
/* 424470 802A9800 0220202D */   daddu    $a0, $s1, $zero
/* 424474 802A9804 82700084 */  lb        $s0, 0x84($s3)
/* 424478 802A9808 3C12802B */  lui       $s2, %hi(D_802AA888_4254F8)
/* 42447C 802A980C 2652A888 */  addiu     $s2, $s2, %lo(D_802AA888_4254F8)
/* 424480 802A9810 00108080 */  sll       $s0, $s0, 2
/* 424484 802A9814 0C05122C */  jal       get_hud_element_script
/* 424488 802A9818 02128021 */   addu     $s0, $s0, $s2
/* 42448C 802A981C 8E030000 */  lw        $v1, ($s0)
/* 424490 802A9820 10620013 */  beq       $v1, $v0, .L802A9870
/* 424494 802A9824 00000000 */   nop
/* 424498 802A9828 82620084 */  lb        $v0, 0x84($s3)
/* 42449C 802A982C 080AA618 */  j         .L802A9860
/* 4244A0 802A9830 00021080 */   sll      $v0, $v0, 2
.L802A9834:
/* 4244A4 802A9834 82900084 */  lb        $s0, 0x84($s4)
/* 4244A8 802A9838 3C12802B */  lui       $s2, %hi(D_802AA8A0_425510)
/* 4244AC 802A983C 2652A8A0 */  addiu     $s2, $s2, %lo(D_802AA8A0_425510)
/* 4244B0 802A9840 00108080 */  sll       $s0, $s0, 2
/* 4244B4 802A9844 0C05122C */  jal       get_hud_element_script
/* 4244B8 802A9848 02128021 */   addu     $s0, $s0, $s2
/* 4244BC 802A984C 8E030000 */  lw        $v1, ($s0)
/* 4244C0 802A9850 10620007 */  beq       $v1, $v0, .L802A9870
/* 4244C4 802A9854 00000000 */   nop
/* 4244C8 802A9858 82820084 */  lb        $v0, 0x84($s4)
/* 4244CC 802A985C 00021080 */  sll       $v0, $v0, 2
.L802A9860:
/* 4244D0 802A9860 00521021 */  addu      $v0, $v0, $s2
/* 4244D4 802A9864 8C450000 */  lw        $a1, ($v0)
/* 4244D8 802A9868 0C0511FF */  jal       set_hud_element_script
/* 4244DC 802A986C 0220202D */   daddu    $a0, $s1, $zero
.L802A9870:
/* 4244E0 802A9870 0C0511EA */  jal       draw_hud_element_clipped
/* 4244E4 802A9874 0220202D */   daddu    $a0, $s1, $zero
/* 4244E8 802A9878 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4244EC 802A987C 8FB40028 */  lw        $s4, 0x28($sp)
/* 4244F0 802A9880 8FB30024 */  lw        $s3, 0x24($sp)
/* 4244F4 802A9884 8FB20020 */  lw        $s2, 0x20($sp)
/* 4244F8 802A9888 8FB1001C */  lw        $s1, 0x1c($sp)
/* 4244FC 802A988C 8FB00018 */  lw        $s0, 0x18($sp)
/* 424500 802A9890 03E00008 */  jr        $ra
/* 424504 802A9894 27BD0030 */   addiu    $sp, $sp, 0x30

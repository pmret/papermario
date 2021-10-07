.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A96EC_42915C
/* 42915C 802A96EC 3C02800E */  lui       $v0, %hi(gBattleStatus+0x83)
/* 429160 802A96F0 8042C0F3 */  lb        $v0, %lo(gBattleStatus+0x83)($v0)
/* 429164 802A96F4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 429168 802A96F8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 42916C 802A96FC 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 429170 802A9700 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 429174 802A9704 AFBF0020 */  sw        $ra, 0x20($sp)
/* 429178 802A9708 10400004 */  beqz      $v0, .L802A971C
/* 42917C 802A970C AFB00018 */   sw       $s0, 0x18($sp)
/* 429180 802A9710 8E240004 */  lw        $a0, 4($s1)
/* 429184 802A9714 0C0511EA */  jal       draw_hud_element_clipped
/* 429188 802A9718 00000000 */   nop
.L802A971C:
/* 42918C 802A971C 8E300008 */  lw        $s0, 8($s1)
/* 429190 802A9720 0C0511EA */  jal       draw_hud_element_clipped
/* 429194 802A9724 0200202D */   daddu    $a0, $s0, $zero
/* 429198 802A9728 0200202D */  daddu     $a0, $s0, $zero
/* 42919C 802A972C 27A50010 */  addiu     $a1, $sp, 0x10
/* 4291A0 802A9730 0C05126B */  jal       get_hud_element_render_pos
/* 4291A4 802A9734 27A60014 */   addiu    $a2, $sp, 0x14
/* 4291A8 802A9738 3C02802B */  lui       $v0, %hi(action_command_smack_UnkActionCommandFunc1)
/* 4291AC 802A973C 8C4298B0 */  lw        $v0, %lo(action_command_smack_UnkActionCommandFunc1)($v0)
/* 4291B0 802A9740 14400008 */  bnez      $v0, .L802A9764
/* 4291B4 802A9744 3C0451EB */   lui      $a0, 0x51eb
/* 4291B8 802A9748 96230044 */  lhu       $v1, 0x44($s1)
/* 4291BC 802A974C 3484851F */  ori       $a0, $a0, 0x851f
/* 4291C0 802A9750 00031C00 */  sll       $v1, $v1, 0x10
/* 4291C4 802A9754 00031403 */  sra       $v0, $v1, 0x10
/* 4291C8 802A9758 00440018 */  mult      $v0, $a0
/* 4291CC 802A975C 080AA5E3 */  j         .L802A978C
/* 4291D0 802A9760 24070001 */   addiu    $a3, $zero, 1
.L802A9764:
/* 4291D4 802A9764 86220068 */  lh        $v0, 0x68($s1)
/* 4291D8 802A9768 14400013 */  bnez      $v0, .L802A97B8
/* 4291DC 802A976C 3484851F */   ori      $a0, $a0, 0x851f
/* 4291E0 802A9770 3C0451EB */  lui       $a0, 0x51eb
/* 4291E4 802A9774 96230044 */  lhu       $v1, 0x44($s1)
/* 4291E8 802A9778 3484851F */  ori       $a0, $a0, 0x851f
/* 4291EC 802A977C 00031C00 */  sll       $v1, $v1, 0x10
/* 4291F0 802A9780 00031403 */  sra       $v0, $v1, 0x10
/* 4291F4 802A9784 00440018 */  mult      $v0, $a0
/* 4291F8 802A9788 24070004 */  addiu     $a3, $zero, 4
.L802A978C:
/* 4291FC 802A978C 8FA50014 */  lw        $a1, 0x14($sp)
/* 429200 802A9790 00031FC3 */  sra       $v1, $v1, 0x1f
/* 429204 802A9794 8FA40010 */  lw        $a0, 0x10($sp)
/* 429208 802A9798 00004010 */  mfhi      $t0
/* 42920C 802A979C 00083143 */  sra       $a2, $t0, 5
/* 429210 802A97A0 00C33023 */  subu      $a2, $a2, $v1
/* 429214 802A97A4 00063400 */  sll       $a2, $a2, 0x10
/* 429218 802A97A8 0C09A1E6 */  jal       func_80268798
/* 42921C 802A97AC 00063403 */   sra      $a2, $a2, 0x10
/* 429220 802A97B0 080AA5FC */  j         .L802A97F0
/* 429224 802A97B4 00000000 */   nop
.L802A97B8:
/* 429228 802A97B8 96230044 */  lhu       $v1, 0x44($s1)
/* 42922C 802A97BC 00031C00 */  sll       $v1, $v1, 0x10
/* 429230 802A97C0 00031403 */  sra       $v0, $v1, 0x10
/* 429234 802A97C4 00440018 */  mult      $v0, $a0
/* 429238 802A97C8 24070004 */  addiu     $a3, $zero, 4
/* 42923C 802A97CC 8FA50014 */  lw        $a1, 0x14($sp)
/* 429240 802A97D0 00031FC3 */  sra       $v1, $v1, 0x1f
/* 429244 802A97D4 8FA40010 */  lw        $a0, 0x10($sp)
/* 429248 802A97D8 00004010 */  mfhi      $t0
/* 42924C 802A97DC 00083143 */  sra       $a2, $t0, 5
/* 429250 802A97E0 00C33023 */  subu      $a2, $a2, $v1
/* 429254 802A97E4 00063400 */  sll       $a2, $a2, 0x10
/* 429258 802A97E8 0C09A20D */  jal       func_80268834
/* 42925C 802A97EC 00063403 */   sra      $a2, $a2, 0x10
.L802A97F0:
/* 429260 802A97F0 8E24000C */  lw        $a0, 0xc($s1)
/* 429264 802A97F4 0C0511EA */  jal       draw_hud_element_clipped
/* 429268 802A97F8 00000000 */   nop
/* 42926C 802A97FC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 429270 802A9800 8FB1001C */  lw        $s1, 0x1c($sp)
/* 429274 802A9804 8FB00018 */  lw        $s0, 0x18($sp)
/* 429278 802A9808 03E00008 */  jr        $ra
/* 42927C 802A980C 27BD0028 */   addiu    $sp, $sp, 0x28

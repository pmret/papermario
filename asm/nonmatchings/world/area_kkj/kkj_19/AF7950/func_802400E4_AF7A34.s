.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400E4_AF7A34
/* AF7A34 802400E4 3C038024 */  lui       $v1, %hi(D_80240E90_AF87E0)
/* AF7A38 802400E8 8C630E90 */  lw        $v1, %lo(D_80240E90_AF87E0)($v1)
/* AF7A3C 802400EC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* AF7A40 802400F0 AFB1001C */  sw        $s1, 0x1c($sp)
/* AF7A44 802400F4 00A0882D */  daddu     $s1, $a1, $zero
/* AF7A48 802400F8 AFB20020 */  sw        $s2, 0x20($sp)
/* AF7A4C 802400FC 00C0902D */  daddu     $s2, $a2, $zero
/* AF7A50 80240100 AFBF0024 */  sw        $ra, 0x24($sp)
/* AF7A54 80240104 AFB00018 */  sw        $s0, 0x18($sp)
/* AF7A58 80240108 00031040 */  sll       $v0, $v1, 1
/* AF7A5C 8024010C 00431021 */  addu      $v0, $v0, $v1
/* AF7A60 80240110 00021080 */  sll       $v0, $v0, 2
/* AF7A64 80240114 3C108024 */  lui       $s0, %hi(D_80240E10_AF8760)
/* AF7A68 80240118 02028021 */  addu      $s0, $s0, $v0
/* AF7A6C 8024011C 8E100E10 */  lw        $s0, %lo(D_80240E10_AF8760)($s0)
/* AF7A70 80240120 3C028008 */  lui       $v0, %hi(gItemTable)
/* AF7A74 80240124 244278E0 */  addiu     $v0, $v0, %lo(gItemTable)
/* AF7A78 80240128 00108140 */  sll       $s0, $s0, 5
/* AF7A7C 8024012C 02028021 */  addu      $s0, $s0, $v0
/* AF7A80 80240130 8E040000 */  lw        $a0, ($s0)
/* AF7A84 80240134 0C04991D */  jal       get_string_width
/* AF7A88 80240138 0000282D */   daddu    $a1, $zero, $zero
/* AF7A8C 8024013C 00021043 */  sra       $v0, $v0, 1
/* AF7A90 80240140 2442FFC4 */  addiu     $v0, $v0, -0x3c
/* AF7A94 80240144 02222823 */  subu      $a1, $s1, $v0
/* AF7A98 80240148 26460006 */  addiu     $a2, $s2, 6
/* AF7A9C 8024014C AFA00010 */  sw        $zero, 0x10($sp)
/* AF7AA0 80240150 AFA00014 */  sw        $zero, 0x14($sp)
/* AF7AA4 80240154 8E040000 */  lw        $a0, ($s0)
/* AF7AA8 80240158 0C04993B */  jal       draw_msg
/* AF7AAC 8024015C 240700FF */   addiu    $a3, $zero, 0xff
/* AF7AB0 80240160 8FBF0024 */  lw        $ra, 0x24($sp)
/* AF7AB4 80240164 8FB20020 */  lw        $s2, 0x20($sp)
/* AF7AB8 80240168 8FB1001C */  lw        $s1, 0x1c($sp)
/* AF7ABC 8024016C 8FB00018 */  lw        $s0, 0x18($sp)
/* AF7AC0 80240170 03E00008 */  jr        $ra
/* AF7AC4 80240174 27BD0028 */   addiu    $sp, $sp, 0x28

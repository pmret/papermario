.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_message_value
/* BC2E8 80125BE8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* BC2EC 80125BEC AFB00030 */  sw        $s0, 0x30($sp)
/* BC2F0 80125BF0 00A0802D */  daddu     $s0, $a1, $zero
/* BC2F4 80125BF4 27A50010 */  addiu     $a1, $sp, 0x10
/* BC2F8 80125BF8 AFBF0034 */  sw        $ra, 0x34($sp)
/* BC2FC 80125BFC 0C00A531 */  jal       int_to_string
/* BC300 80125C00 2406000A */   addiu    $a2, $zero, 0xa
/* BC304 80125C04 0000282D */  daddu     $a1, $zero, $zero
/* BC308 80125C08 27A70010 */  addiu     $a3, $sp, 0x10
/* BC30C 80125C0C 3C088015 */  lui       $t0, 0x8015
/* BC310 80125C10 25085C38 */  addiu     $t0, $t0, 0x5c38
/* BC314 80125C14 00103140 */  sll       $a2, $s0, 5
/* BC318 80125C18 00E51021 */  addu      $v0, $a3, $a1
.L80125C1C:
/* BC31C 80125C1C 80430000 */  lb        $v1, ($v0)
/* BC320 80125C20 90440000 */  lbu       $a0, ($v0)
/* BC324 80125C24 10600008 */  beqz      $v1, .L80125C48
/* BC328 80125C28 00A61021 */   addu     $v0, $a1, $a2
/* BC32C 80125C2C 00481021 */  addu      $v0, $v0, $t0
/* BC330 80125C30 2483FFE0 */  addiu     $v1, $a0, -0x20
/* BC334 80125C34 A0430000 */  sb        $v1, ($v0)
/* BC338 80125C38 24A50001 */  addiu     $a1, $a1, 1
/* BC33C 80125C3C 28A2001F */  slti      $v0, $a1, 0x1f
/* BC340 80125C40 1440FFF6 */  bnez      $v0, .L80125C1C
/* BC344 80125C44 00E51021 */   addu     $v0, $a3, $a1
.L80125C48:
/* BC348 80125C48 00101140 */  sll       $v0, $s0, 5
/* BC34C 80125C4C 00A21021 */  addu      $v0, $a1, $v0
/* BC350 80125C50 240300FD */  addiu     $v1, $zero, 0xfd
/* BC354 80125C54 3C018015 */  lui       $at, 0x8015
/* BC358 80125C58 00220821 */  addu      $at, $at, $v0
/* BC35C 80125C5C A0235C38 */  sb        $v1, 0x5c38($at)
/* BC360 80125C60 8FBF0034 */  lw        $ra, 0x34($sp)
/* BC364 80125C64 8FB00030 */  lw        $s0, 0x30($sp)
/* BC368 80125C68 03E00008 */  jr        $ra
/* BC36C 80125C6C 27BD0038 */   addiu    $sp, $sp, 0x38

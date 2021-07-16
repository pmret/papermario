.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_message_string
/* BC23C 80125B3C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BC240 80125B40 AFB00010 */  sw        $s0, 0x10($sp)
/* BC244 80125B44 0080802D */  daddu     $s0, $a0, $zero
/* BC248 80125B48 AFB20018 */  sw        $s2, 0x18($sp)
/* BC24C 80125B4C 00A0902D */  daddu     $s2, $a1, $zero
/* BC250 80125B50 AFB10014 */  sw        $s1, 0x14($sp)
/* BC254 80125B54 0000882D */  daddu     $s1, $zero, $zero
/* BC258 80125B58 06000008 */  bltz      $s0, .L80125B7C
/* BC25C 80125B5C AFBF001C */   sw       $ra, 0x1c($sp)
/* BC260 80125B60 0C00AB0A */  jal       general_heap_malloc
/* BC264 80125B64 24040400 */   addiu    $a0, $zero, 0x400
/* BC268 80125B68 0040882D */  daddu     $s1, $v0, $zero
/* BC26C 80125B6C 0200202D */  daddu     $a0, $s0, $zero
/* BC270 80125B70 0C049601 */  jal       dma_load_string
/* BC274 80125B74 0220282D */   daddu    $a1, $s1, $zero
/* BC278 80125B78 0220802D */  daddu     $s0, $s1, $zero
.L80125B7C:
/* BC27C 80125B7C 0000282D */  daddu     $a1, $zero, $zero
/* BC280 80125B80 240600FD */  addiu     $a2, $zero, 0xfd
/* BC284 80125B84 3C038015 */  lui       $v1, %hi(gMessageStringVars)
/* BC288 80125B88 24635C38 */  addiu     $v1, $v1, %lo(gMessageStringVars)
/* BC28C 80125B8C 00121140 */  sll       $v0, $s2, 5
/* BC290 80125B90 00432021 */  addu      $a0, $v0, $v1
.L80125B94:
/* BC294 80125B94 02051021 */  addu      $v0, $s0, $a1
/* BC298 80125B98 90430000 */  lbu       $v1, ($v0)
/* BC29C 80125B9C A0830000 */  sb        $v1, ($a0)
/* BC2A0 80125BA0 90420000 */  lbu       $v0, ($v0)
/* BC2A4 80125BA4 10460006 */  beq       $v0, $a2, .L80125BC0
/* BC2A8 80125BA8 00000000 */   nop
/* BC2AC 80125BAC 24A50001 */  addiu     $a1, $a1, 1
/* BC2B0 80125BB0 28A20020 */  slti      $v0, $a1, 0x20
/* BC2B4 80125BB4 1440FFF7 */  bnez      $v0, .L80125B94
/* BC2B8 80125BB8 24840001 */   addiu    $a0, $a0, 1
/* BC2BC 80125BBC A086FFFF */  sb        $a2, -1($a0)
.L80125BC0:
/* BC2C0 80125BC0 12200003 */  beqz      $s1, .L80125BD0
/* BC2C4 80125BC4 00000000 */   nop
/* BC2C8 80125BC8 0C00AB1E */  jal       general_heap_free
/* BC2CC 80125BCC 0220202D */   daddu    $a0, $s1, $zero
.L80125BD0:
/* BC2D0 80125BD0 8FBF001C */  lw        $ra, 0x1c($sp)
/* BC2D4 80125BD4 8FB20018 */  lw        $s2, 0x18($sp)
/* BC2D8 80125BD8 8FB10014 */  lw        $s1, 0x14($sp)
/* BC2DC 80125BDC 8FB00010 */  lw        $s0, 0x10($sp)
/* BC2E0 80125BE0 03E00008 */  jr        $ra
/* BC2E4 80125BE4 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel load_hit_asset
/* 0363C0 8005AFC0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0363C4 8005AFC4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0363C8 8005AFC8 AFB20020 */  sw    $s2, 0x20($sp)
/* 0363CC 8005AFCC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0363D0 8005AFD0 0C016AFA */  jal   get_current_map_header
/* 0363D4 8005AFD4 AFB00018 */   sw    $s0, 0x18($sp)
/* 0363D8 8005AFD8 3C04800E */  lui   $a0, 0x800e
/* 0363DC 8005AFDC 248491E0 */  addiu $a0, $a0, -0x6e20
/* 0363E0 8005AFE0 27A50010 */  addiu $a1, $sp, 0x10
/* 0363E4 8005AFE4 0C016B3A */  jal   load_asset_by_name
/* 0363E8 8005AFE8 0040902D */   daddu $s2, $v0, $zero
/* 0363EC 8005AFEC 8FA40010 */  lw    $a0, 0x10($sp)
/* 0363F0 8005AFF0 0C00AB39 */  jal   heap_malloc
/* 0363F4 8005AFF4 0040882D */   daddu $s1, $v0, $zero
/* 0363F8 8005AFF8 0220202D */  daddu $a0, $s1, $zero
/* 0363FC 8005AFFC 0040802D */  daddu $s0, $v0, $zero
/* 036400 8005B000 0C01BB7C */  jal   decode_yay0
/* 036404 8005B004 0200282D */   daddu $a1, $s0, $zero
/* 036408 8005B008 0C00AB1E */  jal   general_heap_free
/* 03640C 8005B00C 0220202D */   daddu $a0, $s1, $zero
/* 036410 8005B010 8E020000 */  lw    $v0, ($s0)
/* 036414 8005B014 0000202D */  daddu $a0, $zero, $zero
/* 036418 8005B018 AE420004 */  sw    $v0, 4($s2)
/* 03641C 8005B01C 8E020004 */  lw    $v0, 4($s0)
/* 036420 8005B020 0200282D */  daddu $a1, $s0, $zero
/* 036424 8005B024 0C016C8F */  jal   load_hit_data
/* 036428 8005B028 AE420008 */   sw    $v0, 8($s2)
/* 03642C 8005B02C 24040001 */  addiu $a0, $zero, 1
/* 036430 8005B030 0C016C8F */  jal   load_hit_data
/* 036434 8005B034 0200282D */   daddu $a1, $s0, $zero
/* 036438 8005B038 0C00AB4B */  jal   heap_free
/* 03643C 8005B03C 0200202D */   daddu $a0, $s0, $zero
/* 036440 8005B040 8FBF0024 */  lw    $ra, 0x24($sp)
/* 036444 8005B044 8FB20020 */  lw    $s2, 0x20($sp)
/* 036448 8005B048 8FB1001C */  lw    $s1, 0x1c($sp)
/* 03644C 8005B04C 8FB00018 */  lw    $s0, 0x18($sp)
/* 036450 8005B050 03E00008 */  jr    $ra
/* 036454 8005B054 27BD0028 */   addiu $sp, $sp, 0x28


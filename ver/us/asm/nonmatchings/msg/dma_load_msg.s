.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel dma_load_msg
    addiu	$sp,$sp,-40
    sw	$s0,24($sp)
    move	$s0,$a0
    sw	$s2,32($sp)
    move	$s2,$a1
    sw	$s1,28($sp)
    lui	  $s1,%hi(msg_ROM_START)
    addiu $s1,$s1,%lo(msg_ROM_START)
    srl	$v0,$s0,0xe
    addu	$a0,$v0,$s1
    addiu	$a1,$a0,4
    sw	$ra,36($sp)
    jal	dma_copy
    addiu	$a2,$sp,16
    addiu	$a2,$sp,16
    andi	$s0,$s0,0xffff
    sll	$s0,$s0,0x2
    lw	$v0,16($sp)
    addu	$s0,$s0,$s1
    addu	$a0,$v0,$s0
    jal	dma_copy
    addiu	$a1,$a0,8
    move	$a2,$s2
    lw	$a0,16($sp)
    lw	$a1,20($sp)
    addu	$a0,$a0,$s1
    jal	dma_copy
    addu	$a1,$a1,$s1
    lw	$ra,36($sp)
    lw	$s2,32($sp)
    lw	$s1,28($sp)
    lw	$s0,24($sp)
    jr	$ra
    addiu	$sp,$sp,40
